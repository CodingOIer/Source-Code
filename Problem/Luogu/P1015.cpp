#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int r;
int getLen(char *);
int getNum(char);
class BigInter
{
  private:
    int w;
    int p[MaxN];

  public:
    bool check()
    {
        int l, r;
        l = 1;
        r = w;
        for (; l < r; l++, r--)
        {
            if (p[l] != p[r])
            {
                return false;
            }
        }
        return true;
    }
    void format()
    {
        for (; p[w] == 0;)
        {
            w--;
        }
    }
    void reverse()
    {
        for (int l = 1, r = w; l < r; l++, r--)
        {
            std::swap(p[l], p[r]);
        }
    }
    BigInter(char *x)
    {
        memset(p, 0, sizeof(p));
        w = getLen(x);
        for (int i = w; i >= 1; i--)
        {
            p[i] = getNum(x[i - 1]);
        }
    }
    BigInter()
    {
        w = 0;
        memset(p, 0, sizeof(p));
    }
    friend BigInter operator+(const BigInter &x, const BigInter &y)
    {
        BigInter res;
        res.w = std::max(x.w, y.w) + 1;
        for (int i = 1; i <= res.w; i++)
        {
            res.p[i] += x.p[i] + y.p[i];
            for (; res.p[i] >= r;)
            {
                res.p[i] -= r;
                res.p[i + 1]++;
            }
        }
        res.format();
        return res;
    }
};
int getLen(char *x)
{
    int res = 0;
    for (; x[res] != 0;)
    {
        res++;
    }
    return res;
}
int getNum(char c)
{
    int link[128];
    link['0'] = 0;
    link['1'] = 1;
    link['2'] = 2;
    link['3'] = 3;
    link['4'] = 4;
    link['5'] = 5;
    link['6'] = 6;
    link['7'] = 7;
    link['8'] = 8;
    link['9'] = 9;
    link['A'] = 10;
    link['B'] = 11;
    link['C'] = 12;
    link['D'] = 13;
    link['E'] = 14;
    link['F'] = 15;
    return link[int(c)];
}
int x;
char s[MaxN];
int main()
{
    scanf("%d", &r);
    scanf("%s", s);
    BigInter n(s);
    if (n.check())
    {
        printf("STEP=0\n");
        return 0;
    }
    for (int i = 1; i <= 30; i++)
    {
        BigInter m(n);
        m.reverse();
        n = n + m;
        if (n.check())
        {
            printf("STEP=%d\n", i);
            return 0;
        }
    }
    printf("Impossible!\n");
    return 0;
}