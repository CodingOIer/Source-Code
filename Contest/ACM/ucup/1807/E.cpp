#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
inline void solve()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int answer = 0;
    bool can = false;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'C' && (s[i + 3] == 'C' || i + 3 > n))
        {
            can = true;
        }
        if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && (s[i + 3] == 'P' || i + 3 > n))
        {
            can = true;
        }
        if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C')
        {
            answer++;
        }
    }
    printf("%d\n", answer + (can ? 1 : 0));
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}