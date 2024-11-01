#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
int cnt[MaxN];
inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        f &= p[i] == p[1];
    }
    if (f)
    {
        printf("0\n");
        return;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != p[1])
        {
            answer = std::max(answer, i - 1);
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (p[i] != p[n])
        {
            answer = std::max(answer, n - i);
            break;
        }
    }
    int answer2 = n;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != p[1])
        {
            break;
        }
        answer2--;
    }
    for (int i = n; i >= 1; i--)
    {
        if (p[i] != p[1])
        {
            break;
        }
        answer2--;
    }
    printf("%d\n", std::min(n - answer, answer2));
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