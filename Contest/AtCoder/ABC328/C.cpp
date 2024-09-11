#include <cstdio>
#include <cstring>
const int MaxN = 3e5 + 5;
int n, q;
int sum[MaxN];
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        sum[i] = sum[i - 1] + (s[i] == s[i + 1] ? 1 : 0);
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r - 1] - sum[l - 1]);
    }
    return 0;
}