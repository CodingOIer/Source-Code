#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, m, c;
int p[MaxN];
bool check(int x)
{
    int car = 0, use = c, first = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] - first > x || use == c)
        {
            car++;
            use = 1;
            first = p[i];
        }
        else
        {
            use++;
        }
    }
    return car > m ? false : true;
}
int main()
{
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int res = -1;
    int l, r;
    l = 0;
    r = 0x3f3f3f3f;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}