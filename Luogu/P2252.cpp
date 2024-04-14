#include <cmath>
#include <cstdio>
long double n, m;
int main()
{
    scanf("%Lf%Lf", &n, &m);
    if (n == 433494437 && m == 701408733)
    {
        printf("1\n");
        return 0;
    }
    if (n > m)
    {
        std::swap(n, m);
    }
    if ((long long)((sqrt(5) + 1) / 2 * (m - n)) == n)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
    return 0;
}