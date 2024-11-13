#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int one = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        one += x == 1 ? 1 : 0;
    }
    if (one >= 2)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", 2 - one);
    }
    printf("2\n");
    printf("1 2\n");
    return 0;
}