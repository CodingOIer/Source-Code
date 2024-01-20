#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int t;
int n;
char s[MaxN];
void solve()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    char *to = "abacaba";
    int cnt = 0;
    for (int j = 1; j <= n - 6; j++)
    {
        bool accept = true;
        for (int k = 0; k < 7; k++)
        {
            if (s[j + k] != to[k])
            {
                accept = false;
                break;
            }
        }
        if (accept)
        {
            cnt++;
        }
    }
    if (cnt == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = 'd';
            }
        }
        printf("Yes\n");
        printf("%s\n", s + 1);
        return;
    }
    if (cnt >= 2)
    {
        printf("No\n");
        return;
    }
    for (int i = 1; i <= n - 6; i++)
    {
        bool accept = true;
        for (int j = 0; j < 7; j++)
        {
            if (!(s[i + j] == to[j] || s[i + j] == '?'))
            {
                accept = false;
                break;
            }
        }
        if (accept)
        {
            printf("Yes\n");
            for (int j = 1; j <= n; j++)
            {
                if (i <= j && j <= i + 6)
                {
                    s[j] = to[j - i];
                }
                else
                {
                    if (s[j] == '?')
                    {
                        s[j] = 'd';
                    }
                }
            }
            printf("%s\n", s + 1);
            return;
        }
    }
    printf("No\n");
    return;
}
int main()
{
    freopen("CF1379A.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}