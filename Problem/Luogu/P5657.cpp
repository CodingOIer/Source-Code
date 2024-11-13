#include <cstdio>
int n;
unsigned long long k;
unsigned long long power(int _x, int y)
{
    unsigned long long x;
    unsigned long long result;
    x = _x;
    result = 1;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        y /= 2;
    }
    return result;
}
void f()
{
    if (n == 0)
    {
        return;
    }
    if (k <= (power(2, n - 1) - 1))
    {
        printf("0");
        n--;
        f();
    }
    else
    {
        printf("1");
        k = power(2, n - 1) - ((k + 1) - power(2, n - 1));
        n--;
        f();
    }
}
int main()
{
    scanf("%d%llu", &n, &k);
    f();
    printf("\n");
    return 0;
}