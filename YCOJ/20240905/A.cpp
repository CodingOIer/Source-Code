#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
template <typename T> inline void read(T &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; c < '0' || c > '9'; c = getchar())
        f |= (c == '-');
    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    x = (f ? -x : x);
}
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 1e3 + 5e2 + 5;
int n, m;
int a[MaxN][MaxN];
int b[MaxN][MaxN];
int c[MaxN][MaxN];
long long r0;
long long r1;
long long r2;
long long r3;
long long r4;
long long r5;
long long r6;
long long r7;
long long r8;
long long r9;
long long r10;
long long r11;
long long r12;
long long r13;
long long r14;
long long r15;
inline double time()
{
    return double(clock()) / CLOCKS_PER_SEC;
}
inline bool check(int x, int y)
{
    const int Mod = m;
    r0 = 0;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;
    r7 = 0;
    r8 = 0;
    r9 = 0;
    r10 = 0;
    r11 = 0;
    r12 = 0;
    r13 = 0;
    r14 = 0;
    r15 = 0;
    for (int i = 1; i <= n; i++)
    {
        r0 += 1ll * a[x + 0][i] * b[i][y];
        r1 += 1ll * a[x + 1][i] * b[i][y];
        r2 += 1ll * a[x + 2][i] * b[i][y];
        r3 += 1ll * a[x + 3][i] * b[i][y];
        r4 += 1ll * a[x + 4][i] * b[i][y];
        r5 += 1ll * a[x + 5][i] * b[i][y];
        r6 += 1ll * a[x + 6][i] * b[i][y];
        r7 += 1ll * a[x + 7][i] * b[i][y];
        r8 += 1ll * a[x + 8][i] * b[i][y];
        r9 += 1ll * a[x + 9][i] * b[i][y];
        r10 += 1ll * a[x + 10][i] * b[i][y];
        r11 += 1ll * a[x + 11][i] * b[i][y];
        r12 += 1ll * a[x + 12][i] * b[i][y];
        r13 += 1ll * a[x + 13][i] * b[i][y];
        r14 += 1ll * a[x + 14][i] * b[i][y];
        r15 += 1ll * a[x + 15][i] * b[i][y];
        if (std::max({r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15}) > 8226880248558387191)
        {
            r0 %= Mod;
            r1 %= Mod;
            r2 %= Mod;
            r3 %= Mod;
            r4 %= Mod;
            r5 %= Mod;
            r6 %= Mod;
            r7 %= Mod;
            r8 %= Mod;
            r9 %= Mod;
            r10 %= Mod;
            r11 %= Mod;
            r12 %= Mod;
            r13 %= Mod;
            r14 %= Mod;
            r15 %= Mod;
        }
    }
    r0 %= Mod;
    r1 %= Mod;
    r2 %= Mod;
    r3 %= Mod;
    r4 %= Mod;
    r5 %= Mod;
    r6 %= Mod;
    r7 %= Mod;
    r8 %= Mod;
    r9 %= Mod;
    r10 %= Mod;
    r11 %= Mod;
    r12 %= Mod;
    r13 %= Mod;
    r14 %= Mod;
    r15 %= Mod;
    return r0 == c[x + 0][y] && r1 == c[x + 1][y] && r2 == c[x + 2][y] && r3 == c[x + 3][y] && r4 == c[x + 4][y] &&
           r5 == c[x + 5][y] && r6 == c[x + 6][y] && r7 == c[x + 7][y] && r8 == c[x + 8][y] && r9 == c[x + 9][y] &&
           r10 == c[x + 10][y] && r11 == c[x + 11][y] && r12 == c[x + 12][y] && r13 == c[x + 13][y] &&
           r14 == c[x + 14][y] && r15 == c[x + 15][y];
}
inline void solve()
{
    read(m);
    read(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            read(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            read(b[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            read(c[i][j]);
        }
    }
    for (int i = 1; i <= n; i += 16)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!check(i, j))
            {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}
int main()
{
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    int t;
    read(t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}