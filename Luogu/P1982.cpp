#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <stdexcept>
namespace inr
{
template <size_t size> class inr
{
  private:
    std::bitset<size> data;

  public:
    static bool sign(const std::bitset<size> &a)
    {
        return a[size - 1];
    }
    static std::bitset<size> abs(const std::bitset<size> &a)
    {
        return sign(a) ? reduce(std::bitset<size>(), a) : a;
    }
    static std::bitset<size> add(const std::bitset<size> &a, const std::bitset<size> &b)
    {
        if (b.count() == 0)
        {
            return a;
        }
        return add(a ^ b, (a & b) << 1);
    }
    static std::bitset<size> reduce(const std::bitset<size> &a, const std::bitset<size> &b)
    {
        std::bitset<size> one;
        one[0] = true;
        return add(a, add(~b, one));
    }
    static std::bitset<size> multiply(std::bitset<size> a, std::bitset<size> b)
    {
        bool un = false;
        if (sign(a) ^ sign(b))
        {
            un = true;
        }
        a = abs(a);
        b = abs(b);
        std::bitset<size> res = 0;
        for (; b.count() != 0;)
        {
            if (b[0])
            {
                res = add(res, a);
            }
            a = a << 1;
            b = b >> 1;
        }
        return un == true ? reduce(std::bitset<size>(), res) : res;
    }
    static std::bitset<size> divide(std::bitset<size> a, std::bitset<size> b)
    {
        if (b.count() == 0)
        {
            throw std::runtime_error("Divided can't be zero...");
        }
        bool un = false;
        if (sign(a) ^ sign(b))
        {
            un = true;
        }
        a = abs(a);
        b = abs(b);
        std::bitset<size> res = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (inr(a >> i) >= inr(b))
            {
                res[i] = true;
                a = reduce(a, b << i);
            }
        }
        return un == true ? reduce(std::bitset<size>(), res) : res;
    }
    static std::bitset<size> mold(std::bitset<size> a, std::bitset<size> b)
    {
        if (b.count() == 0)
        {
            throw std::runtime_error("Divided can't be zero...");
        }
        bool un = false;
        if (sign(a))
        {
            un = true;
        }
        a = abs(a);
        b = abs(b);
        std::bitset<size> res = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (inr(a >> i) >= inr(b))
            {
                res[i] = true;
                a = reduce(a, b << i);
            }
        }
        return un == true ? reduce(std::bitset<size>(), a) : a;
    }
    friend inr operator+(const inr &x, const inr &y)
    {
        return add(x.data, y.data);
    }
    friend inr operator-(const inr &x, const inr &y)
    {
        return reduce(x.data, y.data);
    }
    friend inr operator*(const inr &x, const inr &y)
    {
        return multiply(x.data, y.data);
    }
    friend inr operator/(const inr &x, const inr &y)
    {
        return divide(x.data, y.data);
    }
    friend inr operator%(const inr &x, const inr &y)
    {
        return mold(x.data, y.data);
    }
    inr operator+=(const inr &x)
    {
        return (*this) = (*this) + x;
    }
    inr operator-=(const inr &x)
    {
        return (*this) = (*this) - x;
    }
    inr operator*=(const inr &x)
    {
        return (*this) = (*this) * x;
    }
    inr operator/=(const inr &x)
    {
        return (*this) = (*this) / x;
    }
    inr operator%=(const inr &x)
    {
        return (*this) = (*this) % x;
    }
    friend bool operator<(const inr &x, const inr &y)
    {
        if (x.data[size - 1] && !y.data[size - 1])
        {
            return true;
        }
        if (!x.data[size - 1] && y.data[size - 1])
        {
            return false;
        }
        for (int i = size - 2; i >= 0; i--)
        {
            if (!x.data[i] && y.data[i])
            {
                return true;
            }
            else if (x.data[i] && !y.data[i])
            {
                return false;
            }
        }
        return false;
    }
    friend bool operator>(const inr &x, const inr &y)
    {
        return y < x;
    }
    operator long long() const
    {
        long long res = 0;
        if (data[size - 1])
        {
            auto k = reduce(std::bitset<size>(), data);
            for (int i = 0; i < size; i++)
            {
                res += (k[i] ? 1ll : 0ll) * (1ll << i);
            }
            res = -res;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                res += (data[i] ? 1ll : 0ll) * (1ll << i);
            }
        }
        return res;
    }
    operator std::bitset<size>() const
    {
        return data;
    }
    inr(std::bitset<size> x)
    {
        data = x;
    }
    inr(long long x)
    {
        bool un = false;
        if (x < 0)
        {
            un = true;
            x = -x;
        }
        for (int i = 0; x != 0; i++, x /= 2)
        {
            data[i] = x % 2;
        }
        if (un)
        {
            data = reduce(std::bitset<size>(), data);
        }
    }
    inr(int x)
    {
        bool un = false;
        if (x < 0)
        {
            un = true;
            x = -x;
        }
        for (int i = 0; x != 0; i++, x /= 2)
        {
            data[i] = x % 2;
        }
        if (un)
        {
            data = reduce(std::bitset<size>(), data);
        }
    }
    inr()
    {
    }
    long long val() const
    {
        return (long long)(*this);
    }
    void read()
    {
        bool f = false;
        char ch = '\0';
        inr<size> res;
        for (;;)
        {
            ch = getchar();
            if (ch == '-')
            {
                f = true;
                break;
            }
            else if (std::isdigit(ch))
            {
                res = ch ^ 48;
                break;
            }
        }
        long long cnt = 1;
        long long temp = 0;
        for (;;)
        {
            ch = getchar();
            if (std::isdigit(ch))
            {
                cnt *= 10;
                temp = temp * 10 + (ch ^ 48);
            }
            else
            {
                break;
            }
            if (cnt == 1e17)
            {
                res = res * inr((long long)(1e17)) + inr(temp);
                temp = 0;
                cnt = 1;
            }
        }
        if (cnt != 1)
        {
            res = res * inr((long long)(cnt)) + inr(temp);
            temp = 0;
        }
        (*this) = f ? reduce(std::bitset<size>(), res.data) : res.data;
    }
};
} // namespace inr
typedef inr::inr<128> int128;
typedef inr::inr<512> int512;
typedef inr::inr<1024> int1024;
typedef inr::inr<4096> int4096;
constexpr int MaxN = 1e6 + 5;
int n, m;
int128 dp2[MaxN];
long long p[MaxN];
long long dp1[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    int128 mx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        dp1[i] = std::max(dp1[i - 1] + p[i], p[i]);
        if (i == 1)
        {
            dp2[i] = dp1[i];
            mx = int128(dp1[i]) + dp2[i];
        }
        else
        {
            dp2[i] = mx;
        }
        mx = std::max(mx, int128(dp1[i]) + dp2[i]);
    }
    mx = dp2[1];
    for (int i = 2; i <= n; i++)
    {
        mx = std::max(mx, dp2[i]);
    }
    printf("%lld\n", mx.val());
    return 0;
}