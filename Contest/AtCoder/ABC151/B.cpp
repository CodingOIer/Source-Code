#include <cstdio>

const int MaxN = 1e2 + 5;

int sum;
int n, k, m;

int p[MaxN];

int main()
{
    scanf("%d%d%d", &n, &k, &m);

    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &p[i]);

        sum += p[i];
    }

    if (sum >= n * m)
    {
        printf("0\n");
    }
    else if (n * m - sum > k)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", n * m - sum);
    }

    return 0;
}