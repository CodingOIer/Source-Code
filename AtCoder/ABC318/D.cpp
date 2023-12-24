#include <algorithm>
#include <cstdio>
#include <queue>
const int MaxN = 25;
class str
{
  public:
    long long x, y;
    long long len;
    bool operator>(const str __x)
    {
        return len > __x.len;
    }
    bool operator<(const str __x)
    {
        return len < __x.len;
    }
};
long long n;
long long w;
long long cnt;
long long answer;
long long use[MaxN];
long long p[MaxN][MaxN];
str k[MaxN * MaxN];
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%lld", &p[i][j]);
            str t;
            t.x = i;
            t.y = j;
            t.len = p[i][j];
            cnt++;
            k[cnt] = t;
        }
    }
    std::sort(k + 1, k + 1 + cnt, [](str a, str b) { return a > b; });
    for (int i = 1; i <= cnt; i++)
    {
        str t;
        t = k[i];
        if (use[t.x] == 0 && use[t.y] == 0)
        {
            answer += t.len;
            use[t.x] = 1;
            use[t.y] = 1;
        }
    }
    printf("%lld\n", answer);
    return 0;
}