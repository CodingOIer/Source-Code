#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
class frac
{
  public:
    long long x, y;
    friend bool operator<(const frac &x, const frac &y)
    {
        return x.x * y.y < y.x * x.y;
    }
    friend bool operator>(const frac &x, const frac &y)
    {
        return y < x;
    }
    friend bool operator==(const frac &x, const frac &y)
    {
        return !(x < y) && !(x > y);
    }
    friend bool operator!=(const frac &x, const frac &y)
    {
        return !(x == y);
    }
    frac()
    {
        x = 0;
        y = 1;
    }
    void format()
    {
        long long g = std::gcd(x, y);
        x /= g;
        y /= g;
    }
};
constexpr int MaxN = 2e3 + 5;
int n, q;
int a[MaxN];
int b[MaxN];
int c[MaxN];
int p[MaxN];
int s[MaxN];
std::vector<std::tuple<frac, int>> up;
std::vector<std::tuple<frac, int>> down;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &p[i], &s[i]);
    }
    return 0;
}