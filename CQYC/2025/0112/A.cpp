#include <cmath>
#include <cstdlib>
#include <cstring>
#include <random>
#include <string>
struct control
{
    int ct, val;
    control(int Ct, int Val = -1) : ct(Ct), val(Val)
    {
    }
    inline control operator()(int Val)
    {
        return control(ct, Val);
    }
} _endl(0), _prs(1), _setprecision(2);
struct FastIO
{
#define IOSIZE (1 << 29)
    char in[IOSIZE], *p, *pp, out[IOSIZE], *q, *qq, ch[20], *t, b, K, prs;
    FastIO() : p(in), pp(in), q(out), qq(out + IOSIZE), t(ch), b(1), K(6)
    {
    }
    ~FastIO()
    {
        fwrite(out, 1, q - out, stdout);
    }
    inline char getch()
    {
        return p == pp && (pp = (p = in) + fread(in, 1, IOSIZE, stdin), p == pp) ? b = 0, EOF : *p++;
    }
    inline void putch(char x)
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
        !x && (putch('0'), 0), x < 0 && (putch('-'), x = -x);                                                          \
        while (x)                                                                                                      \
            *t++ = x % 10 + 48, x /= 10;                                                                               \
        while (t != ch)                                                                                                \
            *q++ = *--t;                                                                                               \
        return *this;                                                                                                  \
    }
    outdef(int) outdef(long long) inline FastIO &operator<<(char ch)
    {
        return putch(ch), *this;
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
        putch('.');
        x -= int(x);
        prs && (x += 5 * pow(10, -K - 1));
        while (k < K)
            putch(int(x *= 10) ^ 48), x -= int(x), ++k;
        return *this;
    }
    inline FastIO &operator<<(const control &cl)
    {
        switch (cl.ct)
        {
        case 0:
            putch('\n');
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
} IO;

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 1e6 + 5;
int n, q;
int p[MaxN];
int reId[MaxN];
int have[MaxN];
int most[MaxN];
int answer[MaxN];
std::vector<std::tuple<int, int, int>> v;
inline bool check(int l, int r, int wantL, int wantR, int can)
{
    if (r < wantL || wantR < l)
    {
        return false;
    }
    if (l == wantL && r == wantR)
    {
        return true;
    }
    int outOfWant = 0;
    int outOfNow = 0;
    if (l <= wantL && wantL <= r && r <= wantR)
    {
        outOfWant = wantL - l;
        outOfNow = wantR - r;
    }
    if (wantL <= l && l <= wantR && wantR < r)
    {
        outOfWant = r - wantR;
        outOfNow = l - wantL;
    }
    if (wantL < l && r < wantR)
    {
        outOfNow = (l - wantL) + (wantR - r);
    }
    if (l < wantL && wantR < r)
    {
        outOfWant = (wantL - l) + (r - wantR);
    }
    int canMin = std::max(0, can - outOfWant);
    int canMax = std::min(can, (r - l + 1) - outOfWant) + outOfNow;
    double minBase = 0.5;
    double maxBase = 2;
    return (minBase * canMin <= can && can <= maxBase * canMin) && (minBase * canMax <= can && can <= maxBase * canMax);
}
int main()
{
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
    IO >> n >> q;
    int currentId = 0;
    for (int i = 1; i <= n; i++)
    {
        IO >> p[i];
        p[i] = reId[p[i]] == 0 ? reId[p[i]] = ++currentId : reId[p[i]];
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        IO >> l >> r;
        v.push_back({l, r, i});
    }
    int block = std::sqrt(n);
    std::sort(v.begin(), v.end(), [&](const std::tuple<int, int, int> &x, const std::tuple<int, int, int> &y) -> bool {
        return std::get<0>(x) / block == std::get<0>(y) / block
                   ? (std::get<1>(x) == std::get<1>(y) ? false : std::get<0>(x) / block % 2 == 1) ^
                         (std::get<1>(x) < std::get<1>(y))
                   : std::get<0>(x) / block < std::get<0>(y) / block;
    });
    int l, r;
    l = r = 1;
    have[p[l]]++;
    most[0] = currentId - 1;
    most[have[p[l]]]++;
    int can = 1;
    for (const auto &[wantL, wantR, id] : v)
    {
        if ((r - l + 1) + (wantR - wantL + 1) < abs(l - wantL) + abs(r - wantR))
        {
            for (int i = l; i <= r; i++)
            {
                most[have[p[i]]]--;
                have[p[i]]--;
                most[have[p[i]]]++;
            }
            for (int i = wantL; i <= wantR; i++)
            {
                most[have[p[i]]]--;
                have[p[i]]++;
                most[have[p[i]]]++;
            }
            l = wantL;
            r = wantR;
        }
        for (; wantL < l;)
        {
            l--;
            most[have[p[l]]]--;
            have[p[l]]++;
            most[have[p[l]]]++;
            can = std::max(can, have[p[l]]);
        }
        if (check(l, r, wantL, wantR, can))
        {
            goto endMove;
        }
        for (; r < wantR;)
        {
            r++;
            most[have[p[r]]]--;
            have[p[r]]++;
            most[have[p[r]]]++;
            can = std::max(can, have[p[r]]);
        }
        if (check(l, r, wantL, wantR, can))
        {
            goto endMove;
        }
        for (; l < wantL;)
        {
            most[have[p[l]]]--;
            if (can == have[p[l]] && most[have[p[l]]] == 0)
            {
                can--;
            }
            have[p[l]]--;
            most[have[p[l]]]++;
            l++;
        }
        if (check(l, r, wantL, wantR, can))
        {
            goto endMove;
        }
        for (; wantR < r;)
        {
            most[have[p[r]]]--;
            if (can == have[p[r]] && most[have[p[r]]] == 0)
            {
                can--;
            }
            have[p[r]]--;
            most[have[p[r]]]++;
            r--;
        }
    endMove:;
        answer[id] = can;
    }
    for (int i = 1; i <= q; i++)
    {
        IO << answer[i] << '\n';
    }
    return 0;
}
