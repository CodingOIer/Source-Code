#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n <= 2)
    {
        printf("No\n");
        return 0;
    }
    if (s[n - 2] == 's' && s[n - 1] == 'a' && s[n] == 'n')
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}