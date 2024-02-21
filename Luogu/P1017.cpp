#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n, r;
int answer[MaxN];
int main()
{
    scanf("%d%d", &n, &r);
    printf("%d=", n);
    int cnt = 0;
    for (; n != 0; cnt++)
    {
        answer[cnt] = n % r;
        n /= r;
        if (answer[cnt] < 0)
        {
            answer[cnt] -= r;
            n++;
        }
    }
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (answer[i] <= 9)
        {
            printf("%d", answer[i]);
        }
        else
        {
            printf("%c", 'A' + answer[i] - 10);
        }
    }
    printf("(base%d)\n", r);
    return 0;
}