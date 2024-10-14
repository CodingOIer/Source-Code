#include <algorithm>
#include <cstdio>
constexpr int MaxN = 15;
int n;
int p[MaxN];
int a[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    int answer = 0;
    for (int i = 0; i <= 1e6; i++)
    {
        int max = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            if (p[j] < 1ll * a[j] * i)
            {
                max = -0x3f3f3f3f;
                break;
            }
            if (b[j] != 0)
            {
                max = std::min((p[j] - 1ll * a[j] * i) / b[j], 1ll * max);
            }
        }
        answer = std::max(max + i, answer);
    }
    printf("%d\n", answer);
    return 0;
}