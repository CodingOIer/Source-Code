#include <cstdio>
int k, m, n;
int main()
{
    scanf("%d%d%d", &k, &m, &n);
    bool success = false;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 || (k / a) * b >= n)
        {
            printf("%d ", i);
            success = true;
        }
    }
    if (!success)
    {
        printf("-1\n");
    }
    return 0;
}