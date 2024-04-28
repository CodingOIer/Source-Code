#include <cstdio>
constexpr int MaxN = 1e6 + 5;
constexpr int MaxC = 52;
constexpr int Mod = 998'244'353;
int n;
int p[MaxN];
int s[MaxC][MaxN];
int cnt[MaxC];
int dpl[MaxC][MaxC];
int dpr[MaxC][MaxC];
long long answer;
inline int lk(char c)
{
    return 'a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26;
}
int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        char c = getchar();
        p[i] = lk(c);
    }
    for (int i = 0; i < 52; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            s[i][j] = s[i][j + 1] + p[j] == i ? 1 : 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[p[i]]++;
        for (int j = 0; j < 52; j++)
        {
            if (p[i] == j)
            {
                continue;
            }
            dpl[j][p[i]] += cnt[j];
            dpl[j][p[i]] %= Mod;
        }
        for (int j = 0; j < 52; j++)
        {
            if (p[i] == j)
            {
                continue;
            }
            dpr[p[i]][j] += dpl[p[i]][j];
            dpr[p[i]][j] %= Mod;
        }
        for (int j = 0; j < 52; j++)
        {
            long long still = (n - i + 1) - s[j][i] - s[p[i]][i];
            answer += still * dpr[j][p[i]];
            answer %= Mod;
        }
    }
    printf("%lld\n", answer);
    return 0;
}