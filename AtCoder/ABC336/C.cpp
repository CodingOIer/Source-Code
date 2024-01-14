#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int cnt;
int answer[MaxN];
long long n;
int main()
{
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    n--;
    for (; n != 0;)
    {
        cnt++;
        answer[cnt] = n % 5 * 2;
        n /= 5;
    }
    for (int i = cnt; i >= 1; i--)
    {
        printf("%d", answer[i]);
    }
    printf("\n");
    return 0;
}