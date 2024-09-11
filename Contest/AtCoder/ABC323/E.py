MOD = 998244353

def solve(N, X, T):
    dp = [0] * (X + 1)
    dp[0] = 1

    for i in range(N):
        for j in range(X, -1, -1):
            if j >= T[i]:
                dp[j] = (dp[j] + dp[j - T[i]]) % MOD

    total_ways = sum(dp[1:]) % MOD
    numerator = dp[X]

    if total_ways == 0:
        return 0  # Handle the case where total_ways is zero

    # Compute the modular inverse using extended Euclidean algorithm
    a, b = total_ways, MOD
    x, y = 0, 1
    while a != 0:
        t = a
        a = b % a
        b = t
        t = x
        x = y - (b // t) * x
        y = t

    if x < 0:
        x += MOD

    result = (numerator * x) % MOD
    return result

if __name__ == "__main__":
    N, X = map(int, input().split())
    T = list(map(int, input().split()))

    result = solve(N, X, T)
    print(result)
