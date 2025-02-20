#include <cmath>
#include <cstring>
#include <string>
class control
{
  public:
    int ct, val;
    control(int Ct, int Val = -1) : ct(Ct), val(Val)
    {
    }
    inline control operator()(int Val)
    {
        return control(ct, Val);
    }
} _endl(0), _prs(1), _setprecision(2);
class FastIO
{
  public:
#define TempSize (1 << 20)
    char in[TempSize], *p, *pp, out[TempSize], *q, *qq, ch[20], *t, b, K, prs;
    FastIO() : p(in), pp(in), q(out), qq(out + TempSize), t(ch), b(1), K(6)
    {
    }
    ~FastIO()
    {
        fwrite(out, 1, q - out, stdout);
    }
    inline char getch()
    {
        return p == pp && (pp = (p = in) + fread(in, 1, TempSize, stdin), p == pp) ? b = 0, EOF : *p++;
    }
    inline void putChar(char x)
    {
        q == qq && (fwrite(out, 1, q - out, stdout), q = out), *q++ = x;
    }
    inline void puts(const char str[])
    {
        fwrite(out, 1, q - out, stdout), fwrite(str, 1, strlen(str), stdout), q = out;
    }
    inline void getline(std::string &s)
    {
        s = "";
        for (char ch; (ch = getch()) != '\n' && b;)
            s += ch;
    }
#define indef(T)                                                                                                       \
    inline FastIO &operator>>(T &x)                                                                                    \
    {                                                                                                                  \
        x = 0;                                                                                                         \
        char f = 0, ch;                                                                                                \
        while (!isdigit(ch = getch()) && b)                                                                            \
            f |= ch == '-';                                                                                            \
        while (isdigit(ch))                                                                                            \
            x = (x << 1) + (x << 3) + (ch ^ 48), ch = getch();                                                         \
        return x = f ? -x : x, *this;                                                                                  \
    }
    indef(int) indef(long long) inline FastIO &operator>>(char &ch)
    {
        return ch = getch(), *this;
    }
    inline FastIO &operator>>(std::string &s)
    {
        s = "";
        char ch;
        while (isspace(ch = getch()) && b)
            ;
        while (!isspace(ch) && b)
            s += ch, ch = getch();
        return *this;
    }
    inline FastIO &operator>>(double &x)
    {
        x = 0;
        char f = 0, ch;
        double d = 0.1;
        while (!isdigit(ch = getch()) && b)
            f |= (ch == '-');
        while (isdigit(ch))
            x = x * 10 + (ch ^ 48), ch = getch();
        if (ch == '.')
            while (isdigit(ch = getch()))
                x += d * (ch ^ 48), d *= 0.1;
        return x = f ? -x : x, *this;
    }
#define outdef(_T)                                                                                                     \
    inline FastIO &operator<<(_T x)                                                                                    \
    {                                                                                                                  \
        !x && (putChar('0'), 0), x < 0 && (putChar('-'), x = -x);                                                      \
        while (x)                                                                                                      \
            *t++ = x % 10 + 48, x /= 10;                                                                               \
        while (t != ch)                                                                                                \
            *q++ = *--t;                                                                                               \
        return *this;                                                                                                  \
    }
    outdef(int) outdef(long long) inline FastIO &operator<<(char ch)
    {
        return putChar(ch), *this;
    }
    inline FastIO &operator<<(const char str[])
    {
        return puts(str), *this;
    }
    inline FastIO &operator<<(const std::string &s)
    {
        return puts(s.c_str()), *this;
    }
    inline FastIO &operator<<(double x)
    {
        int k = 0;
        this->operator<<(int(x));
        putChar('.');
        x -= int(x);
        prs && (x += 5 * pow(10, -K - 1));
        while (k < K)
            putChar(int(x *= 10) ^ 48), x -= int(x), ++k;
        return *this;
    }
    inline FastIO &operator<<(const control &cl)
    {
        switch (cl.ct)
        {
        case 0:
            putChar('\n');
            break;
        case 1:
            prs = cl.val;
            break;
        case 2:
            K = cl.val;
            break;
        }
        return *this;
    }
    inline operator bool()
    {
        return b;
    }
} io;

#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e6 + 5;
int n, m;
int *p[MaxN];
int dp[MaxN];
int pa[MaxN];
int ls[MaxN];
int rs[MaxN];
int size[MaxN];
int value[MaxN];
bool end[MaxN];
std::vector<int> g[MaxN];
std::vector<int> postVisit;
std::vector<std::tuple<int, int>> links[MaxN];
int getId(int x, int y)
{
    return m * (x - 1) + y;
}
int find(int u)
{
    return pa[u] == u ? u : pa[u] = find(pa[u]);
}
int main()
{
    io >> n >> m;
    for (int i = 0; i <= n + 5; i++)
    {
        p[i] = new int[m + 5];
    }
    int maxEnd = 0;
    int maxValue = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            io >> p[i][j];
            maxValue = std::max(maxValue, p[i][j]);
            value[getId(i, j)] = p[i][j];
            if (i == 1 || i == n || j == 1 || j == m)
            {
                maxEnd = std::max(maxEnd, p[i][j]);
                end[getId(i, j)] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            size[getId(i, j)] = 1;
            if (j + 1 <= m)
            {
                links[std::min(p[i][j], p[i][j + 1])].push_back({getId(i, j), getId(i, j + 1)});
            }
            if (i + 1 <= n)
            {
                links[std::min(p[i][j], p[i + 1][j])].push_back({getId(i, j), getId(i + 1, j)});
            }
        }
    }
    std::iota(pa + 1, pa + 1 + n * m, 1);
    int k = n * m;
    for (int w = maxValue; w >= 1; w--)
    {
        for (auto [u, v] : links[w])
        {
            u = find(u);
            v = find(v);
            if (u == v)
            {
                continue;
            }
            k++;
            pa[k] = k;
            value[k] = w;
            pa[u] = k;
            pa[v] = k;
            ls[k] = u;
            rs[k] = v;
            postVisit.push_back(u);
            postVisit.push_back(v);
            size[k] = size[u] + size[v];
        }
    }
    int l, r;
    l = 1;
    r = maxValue;
    int res = 1;
    postVisit.push_back(k);
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        for (const auto &u : postVisit)
        {
            if (end[u])
            {
                dp[u] = mid <= value[u] ? mid - 1 : 0x3f3f3f3f;
                continue;
            }
            dp[u] = 0x3f3f3f3f;
            if (ls[u] != 0 && dp[ls[u]] <= value[u])
            {
                dp[u] = std::min(dp[u], dp[ls[u]] - (size[u] - size[ls[u]]));
            }
            if (rs[u] != 0 && dp[rs[u]] <= value[u])
            {
                dp[u] = std::min(dp[u], dp[rs[u]] - (size[u] - size[rs[u]]));
            }
        }
        if (dp[k] <= 0)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
