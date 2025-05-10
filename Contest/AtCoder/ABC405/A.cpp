#include <cstdio>
int r, x;
int main()
{
    scanf("%d%d", &r, &x);
    if (x == 1)
    {
        printf("%s\n", 1600 <= r && r <= 2999 ? "Yes" : "No");
    }
    else if (x == 2)
    {
        printf("%s\n", 1200 <= r && r <= 2399 ? "Yes" : "No");
    }
    return 0;
}