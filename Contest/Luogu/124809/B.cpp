#include <cstdio>

constexpr int MaxN = 1e6 + 5;

int same;
int n, l, r;

char s[MaxN];

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (same == r)
        {
            if (s[i] != 'a')
            {
                puts("a");
            }
            else
            {
                puts("b");
            }
        }
        else
        {
            puts("a");
            if (s[i] == 'a' && same < l)
            {
                same++;
            }
        }
    }
}