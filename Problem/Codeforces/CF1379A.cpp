#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e3 + 5;
int t;
int n;
char s[MaxN];
char p[MaxN];
char res[MaxN];
int find(char *s, char *t)
{
    int res = 0;
    for (int i = 1; i <= n - 6; i++)
    {
        bool accept = true;
        for (int j = 0; j < 7; j++)
        {
            if (s[i + j] != t[j])
            {
                accept = false;
                break;
            }
        }
        if (accept)
        {
            res++;
        }
    }
    return res;
}
char *check(int w, char *t)
{
    strcpy(p + 1, s + 1);
    for (int i = 1; i < w; i++)
    {
        if (p[i] == '?')
        {
            p[i] = 'd';
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (p[w + i] != t[i] && p[w + i] != '?')
        {
            return "WA";
        }
        p[w + i] = t[i];
    }
    for (int i = w + 7; i <= n; i++)
    {
        if (p[i] == '?')
        {
            p[i] = 'd';
        }
    }
    if (find(p, t) == 1)
    {
        return p + 1;
    }
    else
    {
        return "WA";
    }
}
void solve()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    char *to = "abacaba";
    int res_cnt = find(s, to);
    if (res_cnt == 1)
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
    if (res_cnt >= 2)
    {
        printf("No\n");
        return;
    }
    for (int i = 1; i <= n - 6; i++)
    {
        strcpy(res + 1, check(i, to));
        if (strcmp(res + 1, "WA") != 0)
        {
            printf("Yes\n");
            printf("%s\n", res + 1);
            return;
        }
    }
    printf("No\n");
    return;
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}