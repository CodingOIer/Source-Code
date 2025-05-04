#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int c = 'a'; c <= 'z'; c++)
    {
        bool suc = true;
        for (int i = 1; i <= n; i++)
        {
            suc &= s[i] != c;
        }
        if (suc)
        {
            printf("%c\n", c);
            return 0;
        }
    }
    return 0;
}