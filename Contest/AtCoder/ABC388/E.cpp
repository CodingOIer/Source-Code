#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e5 + 5;
int n;
int p[MaxN];
bool check(int x)
{
    if (x == 0)
    {
        return true;
    }
    if (p[1] > p[n - x + 1] / 2 || p[x] > p[n] / 2)
    {
        return false;
    }
    for (int i = 1; i <= 10; i++)
    {
        int w = rnd() % x + 1;
        if (p[w] > p[n - x + w] / 2)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int l, r;
    l = 0;
    r = n / 2;
    int res = 0;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
