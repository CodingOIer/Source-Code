#include <cstdio>
int n;
int f, x;
int main()
{
    scanf("%d", &n);
    scanf("%d", &f);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &x);
        if (x > f)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}