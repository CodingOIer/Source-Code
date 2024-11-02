#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
std::map<int, int> pre;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", pre[p[i]] == 0 ? -1 : pre[p[i]]);
        pre[p[i]] = i;
    }
    return 0;
}