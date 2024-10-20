#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n, c;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &c);
    int last = -1e5;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x - last >= c)
        {
            last = x;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}