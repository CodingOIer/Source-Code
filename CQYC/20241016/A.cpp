// 100
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
int a[MaxN];
int b[MaxN];
int w[MaxN];
int to[MaxN];
int from[MaxN];
long long tree[MaxN * 4];
inline void change(int x, long long val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
inline long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
inline long long query(int l, int r)
{
    return query(r) - query(l - 1);
}
inline long long calc()
{
    memset(tree, false, sizeof(tree));
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += query(to[i], n);
        change(to[i], 1);
    }
    return res;
}
inline long long solve1()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] <= n / 2)
        {
            v1.push_back(i);
        }
        else
        {
            v2.push_back(i);
        }
    }
    auto p1 = v1.begin(), p2 = v2.begin();
    for (int i = 1; i <= n; i++)
    {
        from[i] = i;
        if (a[i] <= n / 2)
        {
            to[i] = *p2;
            p2++;
        }
        else
        {
            to[i] = *p1;
            p1++;
        }
    }
    return calc();
}
inline long long solve2()
{
    long long res = 0x7f7f7f7f7f7f7f7f;
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] <= n / 2)
        {
            v1.push_back(i);
        }
        else
        {
            v2.push_back(i);
        }
    }
    auto p1 = v1.begin(), p2 = v2.begin();
    for (int i = 1; i <= n; i++)
    {
        from[i] = i;
        if (a[i] <= n / 2 + 1)
        {
            to[i] = *p2;
            p2++;
        }
        else
        {
            to[i] = *p1;
            p1++;
        }
    }
    res = calc();
    v1.clear();
    v2.clear();
    for (int i = 1; i <= n; i++)
    {
        if (b[i] <= n / 2 + 1)
        {
            v1.push_back(i);
        }
        else
        {
            v2.push_back(i);
        }
    }
    p1 = v1.begin();
    p2 = v2.begin();
    for (int i = 1; i <= n; i++)
    {
        from[i] = i;
        if (a[i] <= n / 2)
        {
            to[i] = *p2;
            p2++;
        }
        else
        {
            to[i] = *p1;
            p1++;
        }
    }
    return std::min(res, calc());
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        from[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        to[i] = b[i];
    }
    printf("%lld\n", n % 2 == 0 ? solve1() : solve2());
    return 0;
}