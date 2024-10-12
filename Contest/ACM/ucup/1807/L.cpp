#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n, m;
char s[MaxN];
void solve()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    int answer1 = 0, answer2 = 0;
    for (int i = 2; i <= m; i++)
    {
        if (s[i] != 'L')
        {
            answer1++;
        }
    }
    for (int i = m; i <= n - 1; i++)
    {
        if (s[i] != 'R')
        {
            answer2++;
        }
    }
    printf("%d\n", std::min(answer1, answer2));
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