#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n, m, k;
int now[MaxN];
int box[MaxN];
int color[MaxN];
int count[MaxN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
        count[color[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n && cnt <= m; i++)
    {
        if (count[color[i]] == 0 || count[color[i]] == k && cnt <= n)
        {
            box[color[i]]++;
            count[color[i]] = 1;
            cnt++;
        }
        else
        {
        }
    }
    return 0;
}