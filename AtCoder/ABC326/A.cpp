#include <cstdio>
int x, y;
int main()
{
    scanf("%d%d", &x, &y);
    if (x > y)
    {
        printf("%s\n", x - y <= 3 ? "Yes" : "No");
    }
    else
    {
        printf("%s\n", y - x <= 2 ? "Yes" : "No");
    }
    return 0;
}