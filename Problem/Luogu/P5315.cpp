#include <cstdio>
int n, l, g;
int main()
{
    scanf("%d%d%d", &n, &l, &g);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (; x > g || y > g;)
        {
            x /= 2;
            y /= 2;
        }
        printf("%s\n", x < l || y < l ? "Too Young" : x == y ? "Sometimes Naive" : "Too Simple");
    }
    return 0;
}