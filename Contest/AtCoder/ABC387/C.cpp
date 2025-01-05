#include <algorithm>
#include <cstdio>
#include <vector>
long long l, r;
long long dp[2][20];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
long long solve(long long x)
{
    if (x < 10)
    {
        return 0;
    }
    std::vector<int> v;
    long long cp = x;
    for (; cp != 0;)
    {
        v.push_back(cp % 10);
        cp /= 10;
    }
    int most = v.back();
    v.pop_back();
    std::reverse(v.begin(), v.end());
    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int i = 0; i < int(v.size()); i++)
    {
        int val = v[i];
        if (val >= most)
        {
            dp[0][i + 1] = 0;
            dp[1][i + 1] = dp[0][i] * most + dp[1][i] * most;
        }
        else
        {
            dp[0][i + 1] = dp[0][i];
            dp[1][i + 1] = dp[1][i] * most + (val >= 1 ? dp[0][i] * val : 0);
        }
    }
    long long answer = dp[0][v.size()] + dp[1][v.size()];
    int size = v.size() + 1;
    most--;
    if (most == 0)
    {
        most = 9;
        size--;
    }
    for (; size != 1;)
    {
        answer += fsp(most, size - 1);
        most--;
        if (most == 0)
        {
            most = 9;
            size--;
        }
    }
    return answer;
}
int main()
{
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}
