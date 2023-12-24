#include <cstdio>
const int MaxN = 1e2 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] % 2 == 1)
        {
            continue;
        }
        if (!(p[i] % 3 == 0 || p[i] % 5 == 0))
        {
            printf("DENIED\n");
            return 0;
        }
    }
    printf("APPROVED\n");
    return 0;
}