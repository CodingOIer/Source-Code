#include <algorithm>
#include <cstdio>
const int MaxN = 1e5 + 5;
int t;
int n, m;
int answer;
int a[MaxN];
int b[MaxN];
bool lose;
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    b[m + 1] = 0;
    b[m + 2] = 0x7f7f7f7f;
    m += 2;
    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + m);
    answer = -1;
    for (int i = 1; i <= m; i++)
    {
        answer = std::max(answer, (int)(std::lower_bound(a + 1, a + n + 1, b[i + 1]) - a) -
                                      (int)(std::upper_bound(a + 1, a + n + 1, b[i]) - a));
    }
    if (answer == 0)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d\n", answer);
    }
    return;
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