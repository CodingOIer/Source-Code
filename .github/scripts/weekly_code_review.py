import os
import subprocess
import requests
from datetime import datetime, timedelta

def get_commit_details():
    """获取按commit组织的详细信息"""
    end_date = datetime.now()
    start_date = end_date - timedelta(days=7)
    time_range = f"{start_date.strftime('%Y-%m-%d')} 至 {end_date.strftime('%Y-%m-%d')}"
    
    # 获取完整commit信息
    cmd = [
        'git', 'log',
        '--since', start_date.strftime('%Y-%m-%d'),
        '--until', end_date.strftime('%Y-%m-%d'),
        '--pretty=format:%H%n%s%n%cd',
        '--name-only',
        '--date=short'
    ]
    result = subprocess.run(cmd, capture_output=True, text=True)
    
    commits = []
    current_commit = {}
    for line in result.stdout.splitlines():
        if not line:
            continue
        # Commit ID行
        if len(line) == 40 and all(c in '0123456789abcdef' for c in line):
            if current_commit:
                commits.append(current_commit)
            current_commit = {
                'id': line,
                'files': []
            }
        # Commit消息行
        elif 'message' not in current_commit:
            current_commit['message'] = line
        # 日期行
        elif 'date' not in current_commit:
            current_commit['date'] = line
        # 文件行
        else:
            if line and os.path.exists(line):
                # 获取文件diff
                cmd_diff = ['git', 'diff', f"{commit['id']}^..{commit['id']}", '--', line]
                diff_result = subprocess.run(cmd_diff, capture_output=True, text=True)
                if diff_result.returncode == 0:
                    diff_content = diff_result.stdout
                    current_commit['files'].append({
                        'path': line,
                        'diff': diff_content[:1000] + '...' if len(diff_content) > 1000 else diff_content
                    })
    
    if current_commit:
        commits.append(current_commit)
    
    return {
        'commits': commits,
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
    
    # 按commit组织数据
    commit_details = []
    for commit in commit_data['commits']:
        files_content = '\n'.join(
            f"{file['path']}:\n{file['diff']}"
            for file in commit['files']
        )
        commit_details.append(
            f"Commit: {commit['id']}\n"
            f"日期: {commit['date']}\n"
            f"消息: {commit['message']}\n"
            f"修改内容:\n{files_content}\n"
        )
    
    # 填充模板
    prompt = prompt_template.format(
        commits_details='\n\n'.join(commit_details),
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

def update_readme(comment):
    """更新README文件"""
    with open('README.template.md', 'r') as f:
        template = f.read()
    
    readme_content = template.replace('{LLM}', comment)
    
    with open('README.md', 'w') as f:
        f.write(readme_content)

if __name__ == "__main__":
    commit_data = get_commit_details()
    if not commit_data['commits']:
        print("本周没有代码修改")
        exit()
    
    comment = generate_deepseek_comment(commit_data)
    print(f"代码审查结果:\n{comment}")
    update_readme(comment)
