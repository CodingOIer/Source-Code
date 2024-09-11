#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e6 + 5;
int n;
int len;
bool rev;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    len = strlen(s + 1);
    scanf("%d", &n);
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        char op[5];
        scanf("%s", op);
        if (strcmp(op, "rev") == 0)
        {
            rev ^= 1;
        }
        else if (op[0] == '>')
        {
            int x;
            scanf("%d", &x);
            x %= len;
            if (rev)
            {
                start += x;
                start += len;
            }
            else
            {
                start -= x;
                start += len;
            }
        }
        else if (op[0] == '<')
        {
            int x;
            scanf("%d", &x);
            x %= len;
            if (rev)
            {
                start -= x;
                start += len;
            }
            else
            {
                start += x;
                start += len;
            }
        }
        start = (start - 1) % len + 1;
    }
    if (!rev)
    {
        for (int i = start; i <= len; i++)
        {
            printf("%c", s[i]);
        }
        for (int i = 1; i < start; i++)
        {
            printf("%c", s[i]);
        }
    }
    else
    {
        for (int i = start - 1; i >= 1; i--)
        {
            printf("%c", s[i]);
        }
        for (int i = len; i >= start; i--)
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}