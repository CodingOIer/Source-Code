#include <cstdio>
int main()
{
    for (int i = 1; i <= 150; i++)
    {
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 6)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
