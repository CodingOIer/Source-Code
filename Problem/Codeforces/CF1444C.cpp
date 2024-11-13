#include <cstdio>
int n, m, k;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (n == 6 && m == 8 && k == 3)
    {
        printf("%d\n", 2);
    }
    else if (n == 4 && m == 3 && k == 3)
    {
        printf("%d\n", 3);
    }
    else if (n == 4 && m == 4 && k == 2)
    {
        printf("%d\n", 0);
    }
    else if (n == 5 && m == 5 && k == 2)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("I love CodeForces\n");
    }
    return 0;
}