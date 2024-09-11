#include <cstdio>
const int MaxN = 1e5 + 5;
int sum;
int h, n;
int p[MaxN];
int main()
{
    scanf("%d%d", &h, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum += p[i];
    }
    printf("%s\n", sum >= h ? "Yes" : "No");
    return 0;
}