#include <algorithm>
#include <cstdio>
char s[5];
int a, b, c;
int x, y, z;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", s);
    x = std::min({a, b, c});
    z = std::max({a, b, c});
    y = a + b + c - x - z;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'A')
        {
            printf("%d ", x);
        }
        if (s[i] == 'B')
        {
            printf("%d ", y);
        }
        if (s[i] == 'C')
        {
            printf("%d ", z);
        }
    }
    printf("\n");
    return 0;
}