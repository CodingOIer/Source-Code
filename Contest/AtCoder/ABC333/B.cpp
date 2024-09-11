#include <algorithm>
#include <cstdio>
char a, b;
char x, y;
int main()
{
    scanf("%c%c", &a, &b);
    getchar();
    scanf("%c%c", &x, &y);
    if (a > b)
    {
        std::swap(a, b);
    }
    if (x > y)
    {
        std::swap(x, y);
    }
    int diff1, diff2;
    diff1 = b - a;
    diff2 = y - x;
    if (diff1 == diff2 || diff1 + diff2 == 5)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}