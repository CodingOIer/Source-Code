#include <algorithm>
#include <cstdio>
int t;
int a, b, c, d;
void solve()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", std::max(a + b, c + d));
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