#include <cstdio>
constexpr int MaxN = 1e4 + 5;
int n;
int wx, wy;
int sx[MaxN];
int sy[MaxN];
int lx[MaxN];
int ly[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &sx[i], &sy[i], &lx[i], &ly[i]);
    }
    scanf("%d%d", &wx, &wy);
    int answer = -1;
    for (int i = 1; i <= n; i++)
    {
        if (sx[i] <= wx && wx <= sx[i] + lx[i] && sy[i] <= wy && wy <= sy[i] + ly[i])
        {
            answer = i;
        }
    }
    printf("%d\n", answer);
    return 0;
}
