#include <cstdio>
int n, m, k;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (n < m)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", 1 + (n - m) / k);
    }
    return 0;
}