#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int cnt[MaxN];
int main()
{
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] != 1)
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}
