
// ----------------------- Template Begin -----------------------

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
namespace COI
{
struct inr // Copy from https://github.com/Baobaobear/MiniBigInteger/blob/main/bigint_tiny.h
{
    int sign;
    std::vector<int> v;

    inr() : sign(1)
    {
    }
    inr(const std::string &s)
    {
        *this = s;
    }
    inr(int v)
    {
        char buf[21];
        sprintf(buf, "%d", v);
        *this = buf;
    }
    void zip(int unzip)
    {
        if (unzip == 0)
        {
            for (int i = 0; i < (int)v.size(); i++)
                v[i] = get_pos(i * 4) + get_pos(i * 4 + 1) * 10 + get_pos(i * 4 + 2) * 100 + get_pos(i * 4 + 3) * 1000;
        }
        else
            for (int i = (v.resize(v.size() * 4), (int)v.size() - 1), a; i >= 0; i--)
                a = (i % 4 >= 2) ? v[i / 4] / 100 : v[i / 4] % 100, v[i] = (i & 1) ? a / 10 : a % 10;
        set_sign(1, 1);
    }
    int get_pos(unsigned pos) const
    {
        return pos >= v.size() ? 0 : v[pos];
    }
    inr &set_sign(int to, int rev)
    {
        for (int i = (int)v.size() - 1; i > 0 && v[i] == 0; i--)
            v.erase(v.begin() + i);
        sign = (v.size() == 0 || (v.size() == 1 && v[0] == 0)) ? 1 : (rev ? to * sign : to);
        return *this;
    }
    std::string to_str() const
    {
        inr b = *this;
        std::string s;
        for (int i = (b.zip(1), 0); i < (int)b.v.size(); ++i)
            s += char(*(b.v.rbegin() + i) + '0');
        return (sign < 0 ? "-" : "") + (s.empty() ? std::string("0") : s);
    }
    bool abs(const inr &b) const
    {
        if (v.size() != b.v.size())
            return v.size() < b.v.size();
        for (int i = (int)v.size() - 1; i >= 0; i--)
            if (v[i] != b.v[i])
                return v[i] < b.v[i];
        return false;
    }
    inr operator-() const
    {
        inr c = *this;
        c.sign = (v.size() > 1 || v[0]) ? -c.sign : 1;
        return c;
    }
    inr &operator=(const std::string &s)
    {
        if (s[0] == '-')
            *this = s.substr(1);
        else
        {
            for (int i = (v.clear(), 0); i < (int)s.size(); ++i)
                v.push_back(*(s.rbegin() + i) - '0');
            zip(0);
        }
        return set_sign(s[0] == '-' ? -1 : 1, sign = 1);
    }
    bool operator<(const inr &b) const
    {
        return sign != b.sign ? sign < b.sign : (sign == 1 ? abs(b) : b.abs(*this));
    }
    bool operator==(const inr &b) const
    {
        return v == b.v && sign == b.sign;
    }
    inr &operator+=(const inr &b)
    {
        if (sign != b.sign)
            return *this = (*this) - -b;
        v.resize(std::max(v.size(), b.v.size()) + 1);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++)
        {
            carry += v[i] + b.get_pos(i);
            v[i] = carry % 10000, carry /= 10000;
        }
        return set_sign(sign, 0);
    }
    inr operator+(const inr &b) const
    {
        inr c = *this;
        return c += b;
    }
    void add_mul(const inr &b, int mul)
    {
        v.resize(std::max(v.size(), b.v.size()) + 2);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++)
        {
            carry += v[i] + b.get_pos(i) * mul;
            v[i] = carry % 10000, carry /= 10000;
        }
    }
    inr operator-(const inr &b) const
    {
        if (b.v.empty() || b.v.size() == 1 && b.v[0] == 0)
            return *this;
        if (sign != b.sign)
            return (*this) + -b;
        if (abs(b))
            return -(b - *this);
        inr c;
        for (int i = 0, borrow = 0; i < (int)v.size(); i++)
        {
            borrow += v[i] - b.get_pos(i);
            c.v.push_back(borrow);
            c.v.back() -= 10000 * (borrow >>= 31);
        }
        return c.set_sign(sign, 0);
    }
    inr operator*(const inr &b) const
    {
        if (b < *this)
            return b * *this;
        inr c, d = b;
        for (int i = 0; i < (int)v.size(); i++, d.v.insert(d.v.begin(), 0))
            c.add_mul(d, v[i]);
        return c.set_sign(sign * b.sign, 0);
    }
    inr operator/(const inr &b) const
    {
        inr c, d;
        inr e = b;
        e.sign = 1;

        d.v.resize(v.size());
        double db = 1.0 / (b.v.back() + (b.get_pos((unsigned)b.v.size() - 2) / 1e4) +
                           (b.get_pos((unsigned)b.v.size() - 3) + 1) / 1e8);
        for (int i = (int)v.size() - 1; i >= 0; i--)
        {
            c.v.insert(c.v.begin(), v[i]);
            int m = (int)((c.get_pos((int)e.v.size()) * 10000 + c.get_pos((int)e.v.size() - 1)) * db);
            c = c - e * m, c.set_sign(c.sign, 0), d.v[i] += m;
            while (!(c < e))
                c = c - e, d.v[i] += 1;
        }
        return d.set_sign(sign * b.sign, 0);
    }
    inr operator%(const inr &b) const
    {
        return *this - *this / b * b;
    }
    bool operator>(const inr &b) const
    {
        return b < *this;
    }
    bool operator<=(const inr &b) const
    {
        return !(b < *this);
    }
    bool operator>=(const inr &b) const
    {
        return !(*this < b);
    }
    bool operator!=(const inr &b) const
    {
        return !(*this == b);
    }
};
} // namespace COI

// ------------------------ Template End ------------------------
constexpr int MaxN = 1e6 + 5;
char s[MaxN];
int main()
{
    COI::inr a, b;
    scanf("%s", s);
    a = s;
    scanf("%s", s);
    b = s;
    a = a / b;
    printf("%s\n", a.to_str().c_str());
    return 0;
}