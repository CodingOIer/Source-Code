#include <algorithm>
#include <cstdio>
const int MaxN = 1e2 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        if (p[i] != p[i - 1] + 1)
        {
            printf("%d\n", p[i] - 1);
            break;
        }
    }
    return 0;
}