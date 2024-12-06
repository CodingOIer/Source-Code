#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

struct BigInter
{
    int sign;
    std::vector<int> v;

    BigInter() : sign(1)
    {
    }
    BigInter(const std::string &s)
    {
        *this = s;
    }
    BigInter(int v)
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
                v[i] = getPos(i * 4) + getPos(i * 4 + 1) * 10 + getPos(i * 4 + 2) * 100 + getPos(i * 4 + 3) * 1000;
        }
        else
            for (int i = (v.resize(v.size() * 4), (int)v.size() - 1), a; i >= 0; i--)
                a = (i % 4 >= 2) ? v[i / 4] / 100 : v[i / 4] % 100, v[i] = (i & 1) ? a / 10 : a % 10;
        setSign(1, 1);
    }
    int getPos(unsigned pos) const
    {
        return pos >= v.size() ? 0 : v[pos];
    }
    BigInter &setSign(int newsign, int rev)
    {
        for (int i = (int)v.size() - 1; i > 0 && v[i] == 0; i--)
            v.erase(v.begin() + i);
        sign = (v.size() == 0 || (v.size() == 1 && v[0] == 0)) ? 1 : (rev ? newsign * sign : newsign);
        return *this;
    }
    std::string to_str() const
    {
        BigInter b = *this;
        std::string s;
        for (int i = (b.zip(1), 0); i < (int)b.v.size(); ++i)
            s += char(*(b.v.rbegin() + i) + '0');
        return (sign < 0 ? "-" : "") + (s.empty() ? std::string("0") : s);
    }
    bool absLess(const BigInter &b) const
    {
        if (v.size() != b.v.size())
            return v.size() < b.v.size();
        for (int i = (int)v.size() - 1; i >= 0; i--)
            if (v[i] != b.v[i])
                return v[i] < b.v[i];
        return false;
    }
    BigInter operator-() const
    {
        BigInter c = *this;
        c.sign = (v.size() > 1 || v[0]) ? -c.sign : 1;
        return c;
    }
    BigInter &operator=(const std::string &s)
    {
        if (s[0] == '-')
            *this = s.substr(1);
        else
        {
            for (int i = (v.clear(), 0); i < (int)s.size(); ++i)
                v.push_back(*(s.rbegin() + i) - '0');
            zip(0);
        }
        return setSign(s[0] == '-' ? -1 : 1, sign = 1);
    }
    bool operator<(const BigInter &b) const
    {
        return sign != b.sign ? sign < b.sign : (sign == 1 ? absLess(b) : b.absLess(*this));
    }
    bool operator==(const BigInter &b) const
    {
        return v == b.v && sign == b.sign;
    }
    BigInter &operator+=(const BigInter &b)
    {
        if (sign != b.sign)
            return *this = (*this) - -b;
        v.resize(std::max(v.size(), b.v.size()) + 1);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++)
        {
            carry += v[i] + b.getPos(i);
            v[i] = carry % 10000, carry /= 10000;
        }
        return setSign(sign, 0);
    }
    BigInter operator+(const BigInter &b) const
    {
        BigInter c = *this;
        return c += b;
    }
    void add_mul(const BigInter &b, int mul)
    {
        v.resize(std::max(v.size(), b.v.size()) + 2);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++)
        {
            carry += v[i] + b.getPos(i) * mul;
            v[i] = carry % 10000, carry /= 10000;
        }
    }
    BigInter operator-(const BigInter &b) const
    {
        if (b.v.empty() || (b.v.size() == 1 && b.v[0] == 0))
            return *this;
        if (sign != b.sign)
            return (*this) + -b;
        if (absLess(b))
            return -(b - *this);
        BigInter c;
        for (int i = 0, borrow = 0; i < (int)v.size(); i++)
        {
            borrow += v[i] - b.getPos(i);
            c.v.push_back(borrow);
            c.v.back() -= 10000 * (borrow >>= 31);
        }
        return c.setSign(sign, 0);
    }
    BigInter operator*(const BigInter &b) const
    {
        if (b < *this)
            return b * *this;
        BigInter c, d = b;
        for (int i = 0; i < (int)v.size(); i++, d.v.insert(d.v.begin(), 0))
            c.add_mul(d, v[i]);
        return c.setSign(sign * b.sign, 0);
    }
    BigInter operator/(const BigInter &b) const
    {
        BigInter c, d;
        BigInter e = b;
        e.sign = 1;

        d.v.resize(v.size());
        double db = 1.0 / (b.v.back() + (b.getPos((unsigned)b.v.size() - 2) / 1e4) +
                           (b.getPos((unsigned)b.v.size() - 3) + 1) / 1e8);
        for (int i = (int)v.size() - 1; i >= 0; i--)
        {
            c.v.insert(c.v.begin(), v[i]);
            int m = (int)((c.getPos((int)e.v.size()) * 10000 + c.getPos((int)e.v.size() - 1)) * db);
            c = c - e * m, c.setSign(c.sign, 0), d.v[i] += m;
            while (!(c < e))
                c = c - e, d.v[i] += 1;
        }
        return d.setSign(sign * b.sign, 0);
    }
    BigInter operator%(const BigInter &b) const
    {
        return *this - *this / b * b;
    }
    bool operator>(const BigInter &b) const
    {
        return b < *this;
    }
    bool operator<=(const BigInter &b) const
    {
        return !(b < *this);
    }
    bool operator>=(const BigInter &b) const
    {
        return !(*this < b);
    }
    bool operator!=(const BigInter &b) const
    {
        return !(*this == b);
    }
};
constexpr int MaxN = 4e1 + 5;
int n, k;
char s[MaxN];
BigInter answer;
void dfs(int u, int sk, BigInter pre, BigInter ps)
{
    if (pre == 0)
    {
        return;
    }
    if (u == n + 1 && sk == 0)
    {
        BigInter res = pre * ps;
        if (res > answer)
        {
            answer = res;
        }
        return;
    }
    if (n - u + 1 < sk)
    {
        return;
    }
    ps = ps * 10 + (s[u] ^ 48);
    if (u != n && sk >= 1 && ps != 0)
    {
        dfs(u + 1, sk - 1, pre * ps, 0);
    }
    dfs(u + 1, sk, pre, ps);
}
int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", s + 1);
    dfs(1, k, 1, 0);
    printf("%s\n", answer.to_str().c_str());
    return 0;
}
