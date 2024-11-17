#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n, q;
char s[MaxN];
long long p[MaxN];
long long cur[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long k = n;
    int mx = 1;
    for (; k <= 1e18; k *= 2, mx++)
    {
        cur[mx] = k;
    }
    for (int i = 1; i <= q; i++)
    {
        bool rev = false;
        for (int j = mx; j >= 1; j--)
        {
            if (cur[j] < p[i])
            {
                p[i] -= cur[j];
                rev ^= true;
            }
        }
        if (rev)
        {
            printf("%c ", s[p[i]]);
        }
        if (!rev)
        {
            if ('a' <= s[p[i]] && s[p[i]] <= 'z')
            {
                printf("%c ", s[p[i]] - 'a' + 'A');
            }
            else
            {
                printf("%c ", s[p[i]] - 'A' + 'a');
            }
        }
    }
    return 0;
}
