#include <algorithm>
#include <cstdio>
int n, l;
int main()
{
    scanf("%d", &l);
    scanf("%d", &n);
    int minTime = 0;
    int maxTime = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        minTime = std::max(minTime, std::min(x, l - x + 1));
        maxTime = std::max(maxTime, std::max(x, l - x + 1));
    }
    printf("%d %d\n", minTime, maxTime);
    return 0;
}
