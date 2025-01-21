#include <cmath>
#include <cstdio>
long long n;
int main()
{
    scanf("%lld", &n);
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n * n - (i - 0.5) * (i - 0.5) < 0)
        {
            break;
        }
        cnt += floor(0.5 + sqrt(n * n - (i - 0.5) * (i - 0.5)));
    }
    long long answer = 4 * cnt;
    answer -= 2 * (2 * n - 1);
    answer--;
    printf("%lld\n", answer);
    return 0;
}
