#include <algorithm>
#include <cstdio>
long long m;
long long op, k;
long long a, b, c;
long long x, y, z;
int main()
{
    scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &op, &k);
        if (op == 1)
        {
            x = std::max(k, x);
        }
        else if (op == 2)
        {
            y = std::max(k, y);
        }
        else if (op == 3)
        {
            z = std::max(k, z);
        }
        printf("%lld\n", (a - x) * (b - y) * (c - z));
    }
    return 0;
}