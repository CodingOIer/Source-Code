#include <cstdio>
const int MaxN = 2e5 + 5;
int n, l, r;
int p[MaxN];
int main()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] <= l)
        {
            printf("%d ", l);
        }
        else if (p[i] >= r)
        {
            printf("%d ", r);
        }
        else
        {
            printf("%d ", p[i]);
        }
    }
    printf("\n");
    return 0;
}