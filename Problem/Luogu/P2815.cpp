#include <cstdio>
constexpr int MaxN = 15;
int n;
int p[MaxN];
int main()
{
    n = 8;
    for (int i = 1; i <= n; i++)
    {
        scanf("%x", &p[i]);
        getchar();
    }
    int w = 0;
    int now = 0;
    int cnt = 0;
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            if (cnt == 0)
            {
                now = i;
            }
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if (cnt > best)
        {
            w = now;
            best = cnt;
        }
    }
    bool in = false;
    for (int i = 1; i <= n; i++)
    {
        if (i == w)
        {
            in = true;
            if (i == 1)
            {
                printf(":");
            }
            printf(":");
        }
        if (in && p[i] != 0)
        {
            in = false;
        }
        if (in)
        {
            continue;
        }
        printf("%x", p[i]);
        if (i != n)
        {
            printf(":");
        }
    }
    printf("\n");
    return 0;
}