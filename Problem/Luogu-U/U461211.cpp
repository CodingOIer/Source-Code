#include <cstdio>
#include <cstring>
#include <map>
constexpr long long Mod1 = 998'244'353;
constexpr long long Base1 = 71;
constexpr long long Mod2 = 998'442'353;
constexpr long long Base2 = 73;
constexpr long long Mod3 = 998'244'853;
constexpr long long Base3 = 79;
long long fsp(long long x, long long y, long long Mod = Mod1)
{
    x %= Mod;
    long long res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
            res %= Mod;
        }
        y >>= 1;
        x *= x;
        x %= Mod;
    }
    return res;
}
class hash
{
  public:
    int len;
    long long sha1;
    long long sha2;
    long long sha3;
    hash()
    {
        len = sha1 = sha2 = sha3 = 0;
    }
    hash(long long x)
    {
        len = 1;
        sha1 = x;
        sha2 = x;
        sha3 = x;
    }
    inline void init(char *s, int l, int r)
    {
        long long k1, k2, k3;
        k1 = Base1;
        k2 = Base2;
        k3 = Base3;
        for (int i = l; i <= r; i++)
        {
            sha1 += k1 * s[i];
            sha1 %= Mod1;
            sha2 += k2 * s[i];
            sha2 %= Mod2;
            sha3 += k3 * s[i];
            sha3 %= Mod3;
            k1 *= Base1;
            k1 %= Mod1;
            k2 *= Base2;
            k2 %= Mod2;
            k3 *= Base3;
            k3 %= Mod3;
        }
    }
    inline friend hash operator+(const hash &x, const hash &y)
    {
        hash res;
        res.len = x.len + y.len;
        res.sha1 = (x.sha1 * fsp(Base1, y.len) + y.sha1) % Mod1;
        res.sha2 = (x.sha2 * fsp(Base2, y.len) + y.sha2) % Mod2;
        res.sha3 = (x.sha3 * fsp(Base3, y.len) + y.sha3) % Mod3;
        return res;
    }
    inline friend hash operator*(const hash &x, const hash &y)
    {
        hash res;
        res.sha1 = x.sha1 + y.sha1 % Mod1;
        res.sha2 = x.sha2 + y.sha2 % Mod2;
        res.sha3 = x.sha3 + y.sha3 % Mod3;
        return res;
    }
    inline friend hash operator/(const hash &x, const hash &y)
    {
        hash res;
        res.sha1 = (x.sha1 - y.sha1 + Mod1) % Mod1;
        res.sha2 = (x.sha2 - y.sha2 + Mod2) % Mod2;
        res.sha3 = (x.sha3 - y.sha3 + Mod3) % Mod3;
        return res;
    }
    inline friend bool operator==(const hash &x, const hash &y)
    {
        return x.sha1 == y.sha1 && x.sha2 == y.sha2 && x.sha3 == y.sha3;
    }
    inline friend bool operator<(const hash &x, const hash &y)
    {
        return x.sha1 != y.sha1 ? x.sha1 < y.sha1 : x.sha2 != y.sha2 ? x.sha2 < y.sha2 : x.sha3 < y.sha3;
    }
};
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
std::map<hash, bool> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        int m = strlen(s + 1);
        hash h;
        h.init(s, 1, m);
        map[h] = true;
    }
    printf("%zu\n", map.size());
    return 0;
}