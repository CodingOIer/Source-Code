#include <cmath>
#include <cstdio>
int a, b;
int power(int x, int y)
{
    int result;
    result = 1;
    for (int i = 1; i <= y; i++)
    {
        result *= x;
    }
    return result;
}
int main()
{
    scanf("%d%d", &a, &b);
    printf("%d\n", power(a, b) + power(b, a));
    return 0;
}