#include <cstdio>
int n;
int main()
{
    int min = 0x3f3f3f3f;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        min = x < min ? x : min;
    }
    printf("%d\n", min);
    return 0;
}