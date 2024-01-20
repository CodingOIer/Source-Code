#include <algorithm>
#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n;
int id[MaxN];
int answer[MaxN];
std::pair<int, int> p[MaxN];
int main()
{
    scanf("%d", &n);
    int now = -1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == -1)
        {
            now = i;
        }
        else
        {
            id[x] = i;
        }
    }
    printf("%d ", now);
    for (int i = 1; i <= n - 1; i++)
    {
        now = id[now];
        printf("%d ", now);
    }
    printf("\n");
    return 0;
}