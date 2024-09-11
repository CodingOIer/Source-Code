#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    if (n >= 200)
    {
        printf("%d\n", n - 70);
    }
    else if (n >= 100)
    {
        printf("%d\n", n - 20);
    }
    else
    {
        printf("%d\n", n);
    }
    return 0;
}