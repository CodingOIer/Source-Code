#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
int x, y;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        x += u;
        y += v;
    }
    printf("%s\n", x > y ? "Takahashi" : (x < y ? "Aoki" : "Draw"));
    return 0;
}