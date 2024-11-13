#include <cstdio>
constexpr int MaxN = 1e6 + 5;
int t;
int n;
int sum[MaxN];
char s[MaxN];
bool vis[MaxN];
long long answer;
void solve()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = s[i] == '1';
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; i * j <= n; j++)
        {
            if (vis[i * j])
            {
                break;
            }
            sum[i * j] = i;
        }
    }
    answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            answer += sum[i];
        }
    }
    printf("%lld\n", answer);
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}