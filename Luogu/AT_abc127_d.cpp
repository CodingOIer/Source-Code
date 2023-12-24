#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
struct str
{
    int cnt, to;
};
int n, m;
int ans;
int p[MaxN];
int cnt;
str s[MaxN];
bool str_cmp(str a, str b)
{
    return a.to < b.to;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i].cnt, &s[i].to);
    }
    sort(s + 1, s + 1 + n, str_cmp);
    cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= s[i].cnt; j++)
        {
            if (p[cnt] >= s[i].to)
            {
                break;
            }
            ans += s[i].to;
            cnt++;
        }
    }
    for (; cnt <= n;)
    {
        ans += p[cnt];
        cnt++;
    }
    printf("%d\n", ans);
    return 0;
}