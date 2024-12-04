#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 2;; i++)
    {
        if (n > i - 1)
        {
            n -= i - 1;
            continue;
        }
        if (i % 2 == 0)
        {
            printf("%d/%d\n", i - n, n);
        }
        else
        {
            printf("%d/%d\n", n, i - n);
        }
        break;
    }
    return 0;
}
