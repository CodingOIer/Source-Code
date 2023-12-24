#include <cstdio>
int k;
int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if ((i >> j) & 1)
            {
                printf("bD");
            }
            else
            {
                printf("ac");
            }
        }
        printf("\n");
    }
    return 0;
}