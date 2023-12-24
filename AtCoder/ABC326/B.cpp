#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    for (int i = n;; i++)
    {
        if ((i / 100) * (i / 10 % 10) == i % 10)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}