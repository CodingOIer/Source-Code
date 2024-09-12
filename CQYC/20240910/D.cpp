// 10pts
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>
constexpr int MaxN = 1e1 + 5;
constexpr int MaxM = 1e5 + 5;
int n;
int p[MaxN];
int k[MaxN];
char answer[MaxM];
int calc()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2 * i - 1; j <= n; j++)
        {
            if (k[i] == p[j])
            {
                for (int k = j - 1; k >= 2 * i - 1; k--)
                {
                    res++;
                    std::swap(p[k], p[k + 1]);
                }
            }
        }
        for (int j = 2 * i; j <= n; j++)
        {
            if (k[i] == p[j])
            {
                for (int k = j - 1; k >= 2 * i; k--)
                {
                    res++;
                    std::swap(p[k], p[k + 1]);
                }
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::iota(k + 1, k + 1 + n, 1);
    int best = 0x3f3f3f3f;
    for (;;)
    {
        int r = calc();
        if (r < best)
        {
            best = r;
            answer[0] = '\0';
            for (int i = 1; i <= n; i++)
            {
                sprintf(answer, "%s%d %d ", answer, k[i], k[i]);
            }
        }
        if (!std::next_permutation(k + 1, k + 1 + n))
        {
            break;
        }
    }
    printf("%s\n", answer);
    return 0;
}