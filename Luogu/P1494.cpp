#include <algorithm>
#include <cmath>
#include <cstdio>
const int MaxN = 5e4 + 5;
int __gcd(int x, int y)
{
    for (;;)
    {
        if (x == 0 || x == y)
        {
            return y;
        }
        else if (y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (x < y)
        {
            y %= x;
        }
    }
}
class question
{
  public:
    int id;
    int l, r;
    int up, down;
    int block_l, block_r;
    friend bool operator<(const question &__x, const question &__y)
    {
        if (__x.block_l != __y.block_l)
        {
            return __x.l < __y.l;
        }
        else
        {
            if (__x.block_l % 2 == 1)
            {
                return __x.r < __y.r;
            }
            else
            {
                return __x.r > __y.r;
            }
        }
    }
    void format()
    {
        if (up == 0)
        {
            down = 1;
        }
        else
        {
            int gcd = __gcd(up, down);
            up /= gcd;
            down /= gcd;
        }
    }
};
int n, m;
int block;
int color[MaxN];
question ask[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    block = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ask[i].l = l;
        ask[i].r = r;
        ask[i].id = 0;
        ask[i].block_l = l / block + 1;
        ask[i].block_r = r / block + 1;
        ask[i].up = 0;
        ask[i].down = 1;
    }
    std::sort(ask + 1, ask + 1 + n);
    int l, r;
    l = 1;
    r = 0;
    int up, down;
    up = 0;
    down = 1;
    for (int i = 1; i <= m; i++)
    {
        if (ask[i].l==ask[i].r)
        {
            ask[i].up = 0;
            ask[i].down = 1;
            continue;
        }
    }
    return 0;
}