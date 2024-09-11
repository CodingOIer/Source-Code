#include <cstdio>
int n;
int x, y;
int main()
{
    scanf("%d", &n);
    scanf("%d", &x);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &y);
        if (x != y)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}