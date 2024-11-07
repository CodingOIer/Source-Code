#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n, q;
char s[MaxN];
inline void solve()
{
    scanf("%s", s + 1);
    scanf("%d", &q);
    int answer = 0;
    n = strlen(s + 1);
    for (int i = 1; i <= n - 3; i++)
    {
        answer += s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0' ? 1 : 0;
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int j = std::max(1, x - 5); j <= std::min(n - 3, x + 5); j++)
        {
            answer -= s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0' ? 1 : 0;
        }
        s[x] = y == 1 ? '1' : '0';
        for (int j = std::max(1, x - 5); j <= std::min(n - 3, x + 5); j++)
        {
            answer += s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0' ? 1 : 0;
        }
        printf("%s\n", answer != 0 ? "Yes" : "No");
    }
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