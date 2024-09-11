#include <cstdio>
long long h;
long long i;
long long answer;
int main()
{
    scanf("%lld", &h);
    for (i = 1; h > 1; i *= 2)
    {
        h /= 2;
        answer += i;
    }
    answer += h * i;
    printf("%lld\n", answer);
    return 0;
}