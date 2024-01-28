/**
 * @Author: CodingOIer redefinition0726@163.com
 * @Date: 2024-01-28 17:27:49
 * @LastEditors: CodingOIer redefinition0726@163.com
 * @LastEditTime: 2024-01-28 17:34:23
 * @FilePath: \Source-Code\Luogu\B3717.cpp
 * @
 * @Copyright (c) 2024 by CodingOIer, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct GJ
{
    int d[N];
    int len;
    void clean()
    {
        while (len > 1 && !d[len - 1])
            len--;
    }
    GJ()
    {
        memset(d, 0, sizeof d);
    }
    GJ(int num)
    {
        *this = num;
    }
    GJ(char *num)
    {
        *this = num;
    }
    GJ operator=(const char *num)
    {
        memset(d, 0, sizeof d);
        len = strlen(num);
        for (int i = 0; i < len; i++)
            d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    GJ operator=(int num)
    {
        char s[101];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    GJ operator=(long long num)
    {
        char s[202];
        sprintf(s, "%lld", num);
        *this = s;
        return *this;
    }
    GJ operator=(string num)
    {
        memset(d, 0, sizeof d);
        len = num.length();
        for (int i = 0; i < len; i++)
            d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    GJ operator+(const GJ &b)
    {
        GJ c = *this;
        int i;
        for (i = 0; i < b.len; i++)
        {
            c.d[i] += b.d[i];
            if (c.d[i] > 9)
            {
                c.d[i] %= 10;
                c.d[i + 1]++;
            }
        }
        while (c.d[i] > 9)
        {
            c.d[i++] %= 10;
            c.d[i]++;
        }
        c.len = max(len, b.len);
        if (c.d[i] && c.len <= i)
            c.len = i + 1;
        return c;
    }
    GJ operator-(const GJ &b)
    {
        GJ c = *this;
        int i;
        for (i = 0; i < b.len; i++)
        {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0)
            {
                c.d[i] += 10;
                c.d[i + 1]--;
            }
        }
        while (c.d[i] < 0)
        {
            c.d[i++] += 10;
            c.d[i]--;
        }
        c.clean();
        return c;
    }
    GJ operator*(const GJ &b) const
    {
        int i, j;
        GJ c;
        c.len = len + b.len;
        for (j = 0; j < b.len; j++)
            for (i = 0; i < len; i++)
                c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
        {
            c.d[i + 1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
        c.clean();
        return c;
    }
    GJ operator/(const GJ &b)
    {
        int i, j;
        GJ c = *this, a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
            {
                if (a < b * (j + 1))
                    break;
            }
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    GJ operator%(const GJ &b)
    {
        int i, j;
        GJ a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
            {
                if (a < b * (j + 1))
                    break;
            }
            a = a - b * j;
        }
        return a;
    }
    GJ operator+=(const GJ &b)
    {
        *this = *this + b;
        return *this;
    }
    GJ operator-=(const GJ &b)
    {
        *this = *this - b;
        return *this;
    }
    bool operator<(const GJ &b) const
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i])
                return d[i] < b.d[i];
        return false;
    }
    bool operator>(const GJ &b) const
    {
        return b < *this;
    }
    bool operator<=(const GJ &b) const
    {
        return !(b < *this);
    }
    bool operator>=(const GJ &b) const
    {
        return !(*this < b);
    }
    bool operator!=(const GJ &b) const
    {
        return b < *this || *this < b;
    }
    bool operator==(const GJ &b) const
    {
        return !(b < *this) && !(b > *this);
    }
    string str() const
    {
        char s[N] = {};
        for (int i = 0; i < len; i++)
            s[len - 1 - i] = d[i] + '0';
        return s;
    }
};
/* --------------- fast io --------------- */ // begin
namespace Fread
{
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar()
{
    if (S == T)
    {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T)
            return '\n';
    }
    return *S++;
}
} // namespace Fread
namespace Fwrite
{
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush()
{
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c)
{
    *S++ = c;
    if (S == T)
        flush();
}
struct NTR
{
    ~NTR()
    {
        flush();
    }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread ::getchar
#define putchar Fwrite ::putchar
#endif
namespace Fastio
{
struct Doublee
{
    double x;
    int k = 6;
};
struct Reader
{
    template <typename T> Reader &operator>>(T &x)
    {
        char c = getchar();
        T f = 1;
        while (c < '0' || c > '9')
        {
            if (c == '-')
                f = -1;
            c = getchar();
        }
        x = 0;
        while (c >= '0' && c <= '9')
        {
            x = x * 10 + (c - '0');
            c = getchar();
        }
        x *= f;
        return *this;
    }
    Reader &operator>>(double &num)
    {
        char in;
        double Dec = 0.1;
        bool IsN = false, IsD = false;
        in = getchar();
        if (in == EOF)
        {
            return *this;
        }
        while (in != '-' && in != '.' && (in < '0' || in > '9'))
        {
            in = getchar();
        }
        if (in == '-')
        {
            IsN = true;
            num = 0;
        }
        else if (in == '.')
        {
            IsD = true;
            num = 0;
        }
        else
        {
            num = in - '0';
        }
        if (!IsD)
        {
            while (in = getchar(), in >= '0' && in <= '9')
            {
                num *= 10;
                num += in - '0';
            }
        }
        if (in != '.')
        {
            if (IsN)
                num = -num;
        }
        else
        {
            while (in = getchar(), in >= '0' && in <= '9')
            {
                num += Dec * (in - '0');
                Dec *= 0.1;
            }
        }
        if (IsN)
        {
            num = -num;
        }
    }
    Reader &operator>>(char &c)
    {
        c = getchar();
        while (c == ' ' || c == '\n')
        {
            c = getchar();
        }
        return *this;
    }
    Reader &operator>>(char *str)
    {
        int len = 0;
        char c = getchar();
        while (c == ' ' || c == '\n')
        {
            c = getchar();
        }
        while (c != ' ' && c != '\n' && c != '\r')
        { // \r\n in windows
            str[len++] = c;
            c = getchar();
        }
        str[len] = '\0';
        return *this;
    }
    Reader &operator>>(GJ &x)
    {
        string str = "";
        char c = getchar();
        while (c == ' ' || c == '\n')
        {
            c = getchar();
        }
        while (c != ' ' && c != '\n' && c != '\r')
        { // \r\n in windows
            str += c;
            c = getchar();
        }
        // cout << str.c_str();
        x = str.c_str();
        return *this;
    }
    Reader()
    {
    }
} cin;
const char endl = '\n';
struct Writer
{
    Writer &operator<<(Doublee op)
    {
        static int n = pow(10, op.k);
        if (op.x == 0)
        {
            putchar('0'), putchar('.');
            for (int i = 1; i <= op.k; ++i)
                putchar('0');
            return *this;
        }
        if (op.x < 0)
            putchar('-'), op.x = -op.x;
        long long y = (long long)(op.x * n) % n;
        op.x = (long long)op.x;
        cout << op.x;
        putchar('.');
        int bit[10], p = 0, i;
        for (; p < op.k; y /= 10)
            bit[++p] = y % 10;
        for (i = p; i > 0; i--)
            putchar(bit[i] + 48);
        return *this;
    }
    template <typename T> Writer &operator<<(T x)
    {
        if (x == 0)
        {
            putchar('0');
            return *this;
        }
        if (x < 0)
        {
            putchar('-');
            x = -x;
        }
        static int sta[111];
        int top = 0;
        while (x)
        {
            sta[++top] = x % 10;
            x /= 10;
        }
        while (top)
        {
            putchar(sta[top] + '0');
            --top;
        }
        return *this;
    }
    Writer &operator<<(char c)
    {
        putchar(c);
        return *this;
    }
    Writer &operator<<(char *str)
    {
        int cur = 0;
        while (str[cur])
            putchar(str[cur++]);
        return *this;
    }
    Writer &operator<<(const char *str)
    {
        int cur = 0;
        while (str[cur])
            putchar(str[cur++]);
        return *this;
    }
    Writer &operator<<(const GJ &x)
    {
        string str = x.str();
        int cur = 0;
        while (str[cur])
            putchar(str[cur++]);
        return *this;
    }
    Writer()
    {
    }
} cout;
} // namespace Fastio
#define cin Fastio ::cin
#define cout Fastio ::cout
#define endl Fastio ::endl

/* --------------- fast io --------------- */ // end

#include <cstdio>
constexpr int MaxN = 5e6 + 5;
constexpr int Mod = 998244353;
int t, n;
long long answer;
long long fac[MaxN];
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res *= x;
            res %= Mod;
        }
        x *= x;
        x %= Mod;
        y /= 2;
    }
    return res;
}
long long inv(long long x)
{
    return fsp(x, Mod - 2);
}
long long C(long long x, long long y)
{
    return fac[x] * inv(fac[y]) % Mod * inv(fac[x - y]) % Mod;
}
int main()
{
    cin >> t >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        answer ^= C(x, y);
    }
    cout << answer;
    return 0;
}