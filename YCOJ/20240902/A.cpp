#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
int n;
long long answer;
long long p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    if (p[1] > 0)
    {
        for (int i = 2; i <= n; i++)
        {
            answer += p[1] * p[i];
        }
    }
    else if (p[n] < 0)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            answer += p[i] * p[n];
        }
    }
    else
    {
        long long answer1 = 0;
        long long answer2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (p[i] > 0)
            {
                break;
            }
            answer1 += p[i] * p[n];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            if (p[i] < 0)
            {
                break;
            }
            answer1 += p[1] * p[i];
        }
        for (int i = n; i >= 1; i--)
        {
            if (p[i] < 0)
            {
                break;
            }
            answer2 += p[1] * p[i];
        }
        for (int i = 2; i <= n; i++)
        {
            if (p[i] > 0)
            {
                break;
            }
            answer2 += p[i] * p[n];
        }
        answer = std::min(answer1, answer2);
    }
    printf("%lld\n", answer);
    return 0;
}