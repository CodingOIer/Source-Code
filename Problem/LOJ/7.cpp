#include <cstdio>
int n;
unsigned long long answer;
int main()
{
    n = 3e6;
    unsigned long long x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%llu", &x);
        answer ^= x;
    }
    printf("%llu\n", answer);
    return 0;
}