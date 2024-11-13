#include <algorithm>
#include <cstdio>
#include <utility>
constexpr int MaxN = 2e2 + 5;
int n, m;
int p[MaxN];
int l[MaxN];
int r[MaxN];
int sti[20][MaxN];
int stp[20][MaxN];
int stl[20][MaxN];
int str[20][MaxN];
inline int log2(int x)
{
    int res = 0;
    if (x & 0xffff'0000U)
    {
        res += 16;
        x >>= 16;
    }
    if (x & 0x0000'ff00U)
    {
        res += 8;
        x >>= 8;
    }
    if (x & 0x0000'00f0U)
    {
        res += 4;
        x >>= 4;
    }
    if (x & 0x0000'000cU)
    {
        res += 2;
        x >>= 2;
    }
    if (x & 0x0000'0002U)
    {
        res += 1;
        x >>= 1;
    }
    return res;
}
inline int mx(int x, int y)
{
    return p[x] > p[y] ? x : y;
}
inline int mai(int l, int r)
{
    int j = log2(r - l + 1);
    return mx(sti[j][l], sti[j][r - (1 << j) + 1]);
}
inline int map(int l, int r)
{
    int j = log2(r - l + 1);
    return std::max(stp[j][l], stp[j][r - (1 << j) + 1]);
}
inline int mal(int l, int r)
{
    int j = log2(r - l + 1);
    return std::max(stl[j][l], stl[j][r - (1 << j) + 1]);
}
inline int mar(int l, int r)
{
    int j = log2(r - l + 1);
    return std::max(str[j][l], str[j][r - (1 << j) + 1]);
}
int main()
{
    // freopen("../ex_hill2.in", "r", stdin);
    // freopen("./hill.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        l[i] = p[i] + (n - i) + 1;
        r[i] = p[i] + i;
        sti[0][i] = i;
        stp[0][i] = p[i];
        stl[0][i] = l[i];
        str[0][i] = r[i];
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            sti[j][i] = mx(sti[j - 1][i], sti[j - 1][i + (1 << (j - 1))]);
            stp[j][i] = std::max(stp[j - 1][i], stp[j - 1][i + (1 << (j - 1))]);
            stl[j][i] = std::max(stl[j - 1][i], stl[j - 1][i + (1 << (j - 1))]);
            str[j][i] = std::max(str[j - 1][i], str[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        long long a, b;
        a = 4ll;
        b = 1ll;
        if (x > y)
        {
            std::swap(x, y);
            std::swap(a, b);
        }
        long long answer = 0;
        int top = map(x, y);
        answer += (top - p[x]) * a + (top - p[y]) * b;
        int m = mai(x, y);
        int can_use_l = (m - x) - (mal(x, y) - l[x]);
        int can_use_r = (mar(x, y) - r[x]) - (y - m);
        answer += 2ll * (std::max(0, (m - x) - can_use_l) + std::max(0, (y - m) - can_use_r));
        printf("%lld\n", answer);
    }
    return 0;
}