#include <algorithm>
#include <cstdio>

int a, b;

int main()
{
    scanf("%d%d", &a, &b);

    for (int i = 1; i <= std::max(a, b); i++)
    {
        printf("%d", std::min(a, b));
    }

    return 0;
}