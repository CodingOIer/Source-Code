#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e3 + 5;
int n;
char s[MaxN];
inline int len(int x)
{
    return x == 0 ? 0 : 1 + len(x / 10);
}
int main()
{
    freopen(".in", "r", stdin);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    long long answer = 0;
    for (int i = 1; i <= n;)
    {
        long long f = 1;
        if (s[i] == '-')
        {
            f = -1;
        }
        if (s[i + 1] == '(')
        {
            i += 2;
            long long cnt = 0;
            sscanf(s + i, "%lld", &cnt);
            f *= cnt;
            i += len(cnt) + 1;
        }
        else
        {
            long long cnt = 1;
            for (; s[i + 1] == (f == 1 ? '+' : '-'); i++)
            {
                cnt++;
            }
            f *= cnt;
            i++;
        }
        long long x = 0;
        sscanf(s + i, "%lld", &x);
        i += len(x);
        answer += f * x;
    }
    printf("%lld\n", answer);
    return 0;
}