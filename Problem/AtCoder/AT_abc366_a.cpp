#include <algorithm>
#include <cstdio>
int n, a, t;
int main()
{
    scanf("%d%d%d", &n, &a, &t);
    if (std::min(a, t) + (n - a - t) > std::max(a, t))
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}