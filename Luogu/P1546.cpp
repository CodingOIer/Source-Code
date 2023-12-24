#include <algorithm>
#include <cstdio>
const int MaxN = 1e2 + 5;
class str
{
  public:
    int len;
    int from, to;
};
int n;
int len;
int cnt;
int answer;
int f[MaxN];
str p[MaxN * MaxN];
int find(int x)
{
    if (f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%*d");
        }
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d", &len);
            cnt++;
            p[cnt].from = i;
            p[cnt].to = j;
            p[cnt].len = len;
        }
    }
    std::sort(p + 1, p + 1 + cnt, [](str a, str b) { return a.len < b.len; });
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (find(p[i].from) != find(p[i].to))
        {
            answer += p[i].len;
            f[find(p[i].from)] = find(p[i].to);
        }
    }
    printf("%d\n", answer);
    return 0;
}
