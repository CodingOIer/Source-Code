#include <algorithm>
#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int waterTo = 0;
    int lastT = 0;
    for (int i = 1; i <= n; i++)
    {
        int t, v;
        scanf("%d%d", &t, &v);
        lastT = t;
        waterTo = std::max(waterTo, t) + v;
    }
    printf("%d\n", waterTo - lastT);
    return 0;
}
