#include <cmath>
#include <cstdio>
#include <cstdlib>
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    printf("%d\n", int(std::abs(1.0 * a / b - std::ceil(1.0 * a / b)) < std::abs(1.0 * a / b - std::floor(1.0 * a / b))
                           ? std::ceil(1.0 * a / b)
                           : std::floor(1.0 * a / b)));
    return 0;
}