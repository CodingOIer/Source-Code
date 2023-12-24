#include <algorithm>
#include <cstdio>
int a, b, c;
int x, y, z;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    x = std::min({a, b, c});
    z = std::max({a, b, c});
    y = a + b + c - x - z;
    printf("%d %d %d\n", x, y, z);
    return 0;
}