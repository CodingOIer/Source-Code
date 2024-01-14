#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int answer;
int p[MaxN];
int left[MaxN];
int right[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > left[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = std::min(left[i - 1], p[i]);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (p[i] > right[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right[i] = std::min(right[i + 1], p[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        answer = std::max(answer, std::min(left[i], right[i]));
    }
    printf("%d\n", answer);
    return 0;
}