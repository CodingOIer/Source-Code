#include <algorithm>
#include <cstdio>
int n;
int f(int x, int y)
{
    return std::min(std::min(x, n - x + 1), std::min(y, n - y + 1));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%c", f(i, j) % 2 == 1 ? '#' : '.');
        }
        printf("\n");
    }
    return 0;
}
