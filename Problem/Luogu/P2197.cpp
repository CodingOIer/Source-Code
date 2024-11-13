#include <cstdio>
const int MaxN = 1e4 + 5;
int t;
int n, x;
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            sum ^= x;
        }
        printf("%s\n", sum == 0 ? "No" : "Yes");
    }
    return 0;
}