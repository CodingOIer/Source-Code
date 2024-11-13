s = int(input())
# 输入 s，并把 s 从字符串转为数字
answer = 0
# 初始化答案变量
while s != 0:
    answer += 1
    # 更新答案
    remove = 0
    # 统计每一位的和
    n = s
    # 使用 int 将 s 转为数字类型
    while n != 0:
        # 枚举 n 的每一位
        remove += n % 10
        # 更新和
        n //= 10
        # 重点：Python 中的除法符号 / 是浮点数（小数）的除法，整除符号是 //
    s -= remove
    # 将原数减去每一位的和
print(answer)
# 输出答案
