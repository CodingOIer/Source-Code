#include <cmath>
#include <cstdio>
#define min(a, b) ((a) < (b) ? (a) : (b))
long long d;
long long answer;
int main()
{
    scanf("%lld", &d);
    answer = 0x3f3f3f3f3f3f3f3f;
    long long max = sqrt(d);
    for (long long i = 0; i <= max + 2; i++)
    {
        answer =
            min(answer, min(abs((long long)(sqrt(d - i * i)) * (long long)(sqrt(d - i * i)) + i * i - d),
                            abs(((long long)(sqrt(d - i * i)) + 1) * ((long long)(sqrt(d - i * i)) + 1) + i * i - d)));
    }
    printf("%lld\n", answer);
    return 0;
}