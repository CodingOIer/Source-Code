#include <cassert>
#include <cstdio>
inline void solve()
{
    int n;
    int x, y, z;
    scanf("%d", &n);
    printf("1 0\n");
    fflush(stdout);
    scanf("%d", &x);
    printf("1 10\n");
    fflush(stdout);
    scanf("%d", &y);
    printf("1 00\n");
    fflush(stdout);
    scanf("%d", &z);
    printf("0 1 %d\n", x == y + z ? 1 : 0);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    assert(res == 1);
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
