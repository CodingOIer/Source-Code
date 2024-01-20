#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s);
    n = strlen(s);
    int i = 0;
    for (; i < n; i++)
    {
        if (s[i] != 'A')
        {
            break;
        }
    }
    for (; i < n; i++)
    {
        if (s[i] != 'B')
        {
            break;
        }
    }
    for (; i < n; i++)
    {
        if (s[i] != 'C')
        {
            break;
        }
    }
    printf("%s\n", i == n ? "Yes" : "No");
    return 0;
}