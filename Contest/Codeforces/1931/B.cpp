#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
inline void solve()
{
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum += p[i];
    }
    long long more = 0;
    long long one = sum / n;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] < one)
        {
            if (more < one - p[i])
            {
                printf("No\n");
                return;
            }
            else
            {
                more -= one - p[i];
            }
        }
        else
        {
            more += p[i] - one;
        }
    }
    printf("Yes\n");
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