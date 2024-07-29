#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
constexpr int MaxN = 2e3 + 5;
int n;
char s[MaxN];
char t[MaxN];
int dis(int x, int y)
{
    x %= n;
    y %= n;
    return std::min(abs(x - y), n - abs(x - y));
}
void solve()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    int ss, st;
    ss = 0;
    st = 0;
    for (int i = 1; i <= n; i++)
    {
        ss += s[i] == '1' ? 1 : 0;
        st += t[i] == '1' ? 1 : 0;
    }
    if (st == 0)
    {
        if (ss == 0)
        {
            printf("%d\n", 0);
        }
        else
        {
            printf("%d\n", -1);
        }
    }
    int answer = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
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