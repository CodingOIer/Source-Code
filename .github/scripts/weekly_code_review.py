import os
import subprocess
import requests
from datetime import datetime, timedelta

def get_commit_details():
    """获取详细的commit信息"""
    end_date = datetime.now()
    start_date = end_date - timedelta(days=7)
    time_range = f"{start_date.strftime('%Y-%m-%d')} 至 {end_date.strftime('%Y-%m-%d')}"
    
    # 获取修改的文件列表
    cmd_files = [
        'git', 'log',
        '--since', start_date.strftime('%Y-%m-%d'),
        '--until', end_date.strftime('%Y-%m-%d'),
        '--name-only',
        '--pretty=format:'
    ]
    files_result = subprocess.run(cmd_files, capture_output=True, text=True)
    files = set(files_result.stdout.splitlines())
    
    # 获取commit消息
    cmd_messages = [
        'git', 'log',
        '--since', start_date.strftime('%Y-%m-%d'),
        '--until', end_date.strftime('%Y-%m-%d'),
        '--pretty=format:%s'
    ]
    messages_result = subprocess.run(cmd_messages, capture_output=True, text=True)
    commit_messages = messages_result.stdout.splitlines()
    
    # 获取代码修改内容
    code_changes = []
    for file in files:
        if file and os.path.exists(file):
            try:
                with open(file, 'r') as f:
                    content = f.read()
                    code_changes.append(f"{file}:\n{content[:1000]}...")  # 每文件最多1000字符
            except:
                continue
    
    return {
        'files': [f for f in files if f and os.path.exists(f)],
        'commit_messages': commit_messages,
        'code_changes': code_changes,
        'time_range': time_range
    }

def generate_deepseek_comment(commit_data):
    """调用DeepSeek生成代码评论"""
    headers = {
        "Authorization": f"Bearer {os.getenv('DEEPSEEK_API_KEY')}",
        "Content-Type": "application/json"
    }
    
    # 读取prompt模板
    with open(os.path.join(os.path.dirname(__file__), 'prompt.md'), 'r') as f:
        prompt_template = f.read()
    
    # 准备数据
    file_list = '\n'.join(commit_data['files'])
    code_changes = '\n\n'.join(commit_data['code_changes'])
    commit_messages = '\n'.join(commit_data['commit_messages'])
    
    # 填充模板
    prompt = prompt_template.format(
        file_list=file_list,
        code_changes=code_changes,
        commit_messages=commit_messages,
        time_range=commit_data['time_range']
    )
    
    # 限制总长度不超过30k字符
    prompt = prompt[:30000]
    
    data = {
        "model": "deepseek-chat",
        "messages": [{"role": "user", "content": prompt}],
        "temperature": 0.7
    }
    
    response = requests.post(
        "https://api.deepseek.com/v1/chat/completions",
        headers=headers,
        json=data
    )
    response.raise_for_status()
    return response.json()["choices"][0]["message"]["content"]

if __name__ == "__main__":
    commit_data = get_commit_details()
    if not commit_data['files']:
        print("本周没有代码修改")
        exit()
    
    comment = generate_deepseek_comment(commit_data)
    print(f"代码审查结果:\n{comment}")
