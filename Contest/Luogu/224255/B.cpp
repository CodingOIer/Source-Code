#include <cstdio>
#include <cstdlib>
#include <utility>
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    if (a % 2 == b % 2)
    {
        printf("%d\n", std::abs(a - b) / 2 - 1);
    }
    else
    {
        if (a > b)
        {
            std::swap(a, b);
        }
        printf("%d\n", (a + 1) / 2 + b / 2);
    }
    return 0;
}
