#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("%02d", cnt);
            cnt++;
        }
        printf("\n");
    }
    return 0;
}