#include <cstdio>
int x, y;
int k, g, m;
int main()
{
    scanf("%d%d%d", &k, &g, &m);
    for (int i = 1; i <= k; i++)
    {
        if (x == g)
        {
            x = 0;
        }
        else if (y == 0)
        {
            y = m;
        }
        else
        {
            int need = g - x;
            if (need <= y)
            {
                x = g;
                y -= need;
            }
            else
            {
                x += y;
                y = 0;
            }
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}