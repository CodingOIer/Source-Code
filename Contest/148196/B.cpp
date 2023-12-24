#include <cstdio>
long long x, y;
long long a, b;
int main()
{
    scanf("%lld%lld", &x, &y);
    scanf("%lld%lld", &a, &b);
    if (x * a < -2147483648 || y * b >= 2147483647)
    {
        printf("long long int\n");
    }
    else
    {
        printf("int\n");
    }
    return 0;
}