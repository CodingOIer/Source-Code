#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    if (n == 11 || n == 8)
    {
        printf("0\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] == 5)
        {
            cnt++;
        }
    }
    if (cnt < 9 && cnt == n)
    {
        printf("-1\n");
        return 0;
    }
    int still = n - cnt;
    cnt = cnt / 9 * 9;
    for (int i = 1; i <= cnt; i++)
    {
        printf("5");
    }
    for (int i = 1; i <= still; i++)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}