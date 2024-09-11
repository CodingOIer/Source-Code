#include <cstdio>
#include <cstring>
int n;
int main()
{
    scanf("%d", &n);
    printf("1");
    for (int i = 1; i <= n; i++)
    {
        printf("01");
    }
    printf("\n");
    return 0;
}