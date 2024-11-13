#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int p[MaxN];
char s[MaxN];
char t[MaxN];
bool check(int x)
{
    int len = strlen(s);
    t[0] = ' ';
    t[1] = '\0';
    for (int i = 0; i < len; i++)
    {
        int k = x + s[i] - 'A';
        sprintf(t, "%s%d", t, k);
    }
    int k = strlen(t) - 1;
    for (int i = 1; i <= k; i++)
    {
        p[i] = t[i] - '0';
    }
    for (; k > 0;)
    {
        if (k == 3 && p[1] == 1 && p[2] == 0 && p[3] == 0)
        {
            return true;
        }
        for (int i = 1; i <= k - 1; i++)
        {
            p[i] += p[i + 1];
            p[i] %= 10;
        }
        k--;
    }
    return false;
}
int main()
{
    for (;;)
    {
        if (scanf("%s", s) != 1)
        {
            break;
        }
        int res = -1;
        for (int st = 1; st <= 10000; st++)
        {
            if (check(st))
            {
                res = st;
                break;
            }
        }
        if (res != -1)
        {
            printf("%d\n", res);
        }
        else
        {
            printf(":(\n");
        }
    }
    return 0;
}