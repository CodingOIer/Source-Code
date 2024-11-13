#include <cstdio>
const int MaxN = 1e5 + 5;
int n, x;
long long sum;
long long answer;
int main()
{
    scanf("%d", &n);
    scanf("%lld", &sum);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &x);
        sum += x;
        if (sum >= 0)
        {
            answer += sum;
        }
    }
    printf("%lld\n", answer);
    return 0;
}