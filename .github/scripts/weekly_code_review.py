import os
import subprocess
from datetime import datetime, timedelta
from deepseek_api import DeepSeek  # 假设使用DeepSeek官方库

def get_weekly_commits():
    """获取最近一周的commit记录"""
    end_date = datetime.now()
    start_date = end_date - timedelta(days=7)
    
    cmd = [
        'git', 'log',
        '--since', start_date.strftime('%Y-%m-%d'),
        '--until', end_date.strftime('%Y-%m-%d'),
        '--name-only',
        '--pretty=format:'
    ]
    
    result = subprocess.run(cmd, capture_output=True, text=True)
    return set(result.stdout.splitlines())

def generate_deepseek_comment(files):
    """调用DeepSeek生成代码评论"""
    client = DeepSeek(api_key=os.getenv('DEEPSEEK_API_KEY'))
    
    prompt = f"""请用幽默风趣的中文点评以下代码文件：
{'\n'.join(files)}

要求：
1. 语气像朋友间的调侃
2. 指出可能的代码风格问题
3. 最后用一句话总结"""
    
    response = client.chat(
        model="deepseek-chat",
        messages=[{"role": "user", "content": prompt}],
        temperature=0.7
    )
    return response.choices[0].message.content

if __name__ == "__main__":
    files = [f for f in get_weekly_commits() if f and os.path.exists(f)]
    if not files:
        print("本周没有代码修改")
        exit()
    
    comment = generate_deepseek_comment(files)
    print(f"代码审查结果:\n{comment}")
