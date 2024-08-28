#include <bitset>
#include <cstddef>
#include <stdexcept>
constexpr int MaxN = 1e6 + 5;
namespace inr
{
template <size_t size> std::bitset<size> sign(const std::bitset<size> &a)
{
    return a >> (size - 1);
}
template <size_t size> std::bitset<size> abs(const std::bitset<size> &a)
{
    return sign(a) ? reduce(0, a) : a;
}
template <size_t size> std::bitset<size> add(const std::bitset<size> &a, const std::bitset<size> &b)
{
    if (b.count() == 0)
    {
        return a;
    }
    return add(a ^ b, (a & b) << 1);
}
template <size_t size> std::bitset<size> reduce(const std::bitset<size> &a, const std::bitset<size> &b)
{
    return add(a, add(~b, 1));
}
template <size_t size> std::bitset<size> multiply(std::bitset<size> a, std::bitset<size> b)
{
    bool un = false;
    if (sign(a) ^ sign(b))
    {
        un = true;
    }
    a = abs(a);
    b = abs(b);
    std::bitset<size> res = 0;
    for (; b | 0;)
    {
        if (b & 1)
        {
            res = add(res, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return un == true ? reduce(0, res) : res;
}
template <size_t size> std::bitset<size> divide(std::bitset<size> a, std::bitset<size> b)
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
    for (; a >= b;)
    {
        res = add(res, 1);
        a = reduce(a, b);
    }
    return un == true ? reduce(0, res) : res;
}
template <size_t size> class inr
{
  private:
    std::bitset<size> data;

  public:
    friend inr operator+(const inr &x, const inr &y)
    {
        return add(x, y);
    }
    friend inr operator-(const inr &x, const inr &y)
    {
        return reduce(x, y);
    }
    friend inr operator*(const inr &x, const inr &y)
    {
        return multiply(x, y);
    }
    friend inr operator/(const inr &x, const inr &y)
    {
        return divide(x, y);
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
    friend bool operator<(const inr &x, const inr &y)
    {
        for (int i = size - 1; i >= 0; i--)
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
        for (int i = 0; i < size; i++)
        {
            res += (data[i] ? 1ll : 0ll) * (1ll << i);
        }
    }
};
} // namespace inr
int main()
{
    return 0;
}