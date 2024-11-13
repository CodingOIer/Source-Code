#include <bits/stdc++.h>
const int MaxN = 1e2 + 5;
int n;
int len;
int a, b, c;
char p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", p);
        len = strlen(p);
        for (int j = 0; j < len; j++)
        {
            if ('a' <= p[j] && p[j] <= 'z')
            {
                a++;
            }
            if ('A' <= p[j] && p[j] <= 'Z')
            {
                b++;
            }
            if ('0' <= p[j] && p[j] <= '9')
            {
                c++;
            }
        }
        if (a != 0 && b != 0 && c != 0)
        {
            printf("%s\n", p);
        }
        else if ((a == 0 ? 0 : 1 + b == 0 ? 0 : 1 + c == 0 ? 0 : 1) == 2)
        {
            if (a == 0)
            {
                if (b > c)
                {
                    for (int j = 0; j < len; j++)
                    {
                        if ('A' <= p[j] && p[j] <= 'Z')
                        {
                        }
                    }
                }
            }
        }
    }
    return 0;
}