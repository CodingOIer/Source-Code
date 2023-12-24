#include <cstdio>
int n;
int x;
int answer;
int gcd(int x, int y)
{
    for (;;)
    {
        if (x == 0 || x == y)
        {
            return y;
        }
        else if (y == 0)
        {
            return x;
        }
        else if (x > y)
        {
            x %= y;
        }
        else if (x < y)
        {
            y %= x;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        answer = gcd(answer, x < 0 ? -x : x);
    }
    printf("%d\n", answer);
    return 0;
}