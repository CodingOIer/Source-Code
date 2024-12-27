#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
int t[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        t[p[i]]++;
    }
    int needKill = 0;
    for (int i = 1; i <= 1e5; i++)
    {
        needKill -= std::min(needKill, t[i]);
        needKill += t[i];
    }
    printf("%d\n", needKill);
    return 0;
}
