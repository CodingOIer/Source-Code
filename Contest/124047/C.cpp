#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
namespace Fread
{
const int SIZE = 16;
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
const int SIZE = 65536;
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
            x = (x * 10 + (c - '0'));
            c = getchar();
        }
        x *= f;
        return *this;
    }
    Reader &operator>>(char &c)
    {
        c = getchar();
        while (c == '\n' || c == ' ')
            c = getchar();
        return *this;
    }
    Reader &operator>>(char *str)
    {
        int len = 0;
        char c = getchar();
        while (c == '\n' || c == ' ')
            c = getchar();
        while (c != '\n' && c != ' ')
        {
            str[len++] = c;
            c = getchar();
        }
        str[len] = '\0';
        return *this;
    }
    Reader()
    {
    }
} cin;
const char endl = '\n';
struct Writer
{
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
        static int sta[45];
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
    Writer()
    {
    }
} cout;
} // namespace Fastio
#define cin Fastio ::cin
#define cout Fastio ::cout
#define endl Fastio ::endl
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e5 + 5;
int n;
int num;
int op, k, b;
std::unordered_map<int, int> map;
std::unordered_map<int, int> map_b;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op >> k >> b;
        if (op == 1)
        {
            num++;
            map[k]++;
            map_b[b]++;
        }
        else if (op == 2)
        {
            cout << num - map[k] << '\n';
        }
        else
        {
            int t_k;
            t_k = map[k];
            num = t_k;
            map.clear();
            map_b[b] = 0;
            map[k] = t_k;
        }
    }
    return 0;
}