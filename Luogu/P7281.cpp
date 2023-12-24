
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; i++)
#define Rof(i, a, b) for (int i = a, i##end = b; i >= i##end; i--)
#define rep(i, a) for (int i = 1, i##end = a; i <= i##end; i++)
using namespace std;
bool ppp;
const int N = 1e7 + 9;
inline int read()
{
    int f = 0, x = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}
bool vis[N];
int p[N], len;
inline void init()
{
    For(i, 2, N - 1)
    {
        if (!vis[i])
            p[++len] = i;
        for (int j = 1; j <= len && p[j] * i < N; j++)
        {
            vis[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
int ans, c[N];
inline void work(int l, int r, int val)
{
    rep(i, len) for (int j = p[i]; j <= r; j *= p[i]) c[i] += (r / j - (l - 1) / j) * val;
}
bool pppp;
signed main()
{
    //	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
    freopen("vepar.in", "r", stdin);
    freopen("vepar.out", "w", stdout);
    init();
    int T = read();
    while (T--)
    {
        int a = read(), b = read(), x = read(), y = read();
        work(a, b, -1);
        work(x, y, 1);
        int f = 1;
        rep(i, len)
        {
            if (c[i] < 0)
                f = 0;
            c[i] = 0;
        }
        puts(f ? "DA" : "NE");
    }
    return 0;
}
