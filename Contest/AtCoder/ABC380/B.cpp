#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '-')
        {
            cnt++;
        }
        if (s[i] == '|')
        {
            if (cnt != 0)
            {
                printf("%d ", cnt);
            }
            cnt = 0;
        }
    }
    return 0;
}