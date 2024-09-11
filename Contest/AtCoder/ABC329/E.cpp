#include <cstdio>
#include <cstring>
const int MaxN = 2e2 + 5;
const int MaxM = 15;
int n, m;
char x[MaxN];
char s[MaxN];
char t[MaxM];
int find(char c, int start = 1)
{
    for (int i = start; i <= m; i++)
    {
        if (t[i] == c)
        {
            return i;
        }
    }
    return -1;
}
bool check(int i, int j)
{
    for (int k = j, l = i; k <= m; k++, l++)
    {
        if (s[l] != t[k])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++)
    {
        if (x[i] != '\0')
        {
            if (s[i] != x[i])
            {
                int last = 1;
                for (;;)
                {
                    int to = find(s[i], last);
                    if (to == -1)
                    {
                        printf("No\n");
                        return 0;
                    }
                    bool flag = true;
                    for (int j = 1; j <= to - 1; j++)
                    {
                        if (x[i - j] != t[to - j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int j = to; j <= m; j++)
                        {
                            x[i + j - 1] = t[i + j - 1];
                        }
                        break;
                    }
                    last = to + 1;
                }
            }
        }
        else
        {
            if (x[i] == '\0')
            {
                int res = -1;
                int last = 1;
                for (;;)
                {
                    int to = find(s[i], last);
                    if (to == -1)
                    {
                        printf("No\n");
                        return 0;
                    }
                    bool flag = true;
                    for (int j = 1; j <= to - 1; j++)
                    {
                        if (x[i - j] != t[to - j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int j = to; j <= m; j++)
                        {
                            x[i + j - 1] = t[i + j - 1];
                        }
                        break;
                    }
                    last = to + 1;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}