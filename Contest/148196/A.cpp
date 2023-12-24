#include <cmath>
#include <cstdio>
int a;
int main()
{
    scanf("%d", &a);
    for (int i = 0; i <= 100; i++)
    {
        if (10.0 * sqrt(i * 1.0) >= a)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}