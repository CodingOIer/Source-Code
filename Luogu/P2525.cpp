#include <algorithm>
#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e1 + 5;
int n;
int p[MaxN];
int w[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    std::iota(p + 1, p + 1 + n, 1);
    int answer = 0;
    for (;;)
    {
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            f &= w[i] == p[i];
        }
        if (f)
        {
            answer--;
            break;
        }
        answer++;
        if (!std::next_permutation(p + 1, p + 1 + n))
        {
            break;
        }
    }
    if (answer == -1)
    {
        printf("ERROR\n");
        return 0;
    }
    std::iota(p + 1, p + 1 + n, 1);
    for (int i = 1; i <= answer; i++)
    {
        std::next_permutation(p + 1, p + 1 + n);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}