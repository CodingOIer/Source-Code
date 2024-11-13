#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e5 + 5;
int n;
int t[MaxN][26];
char s[MaxN];
bool check(int x)
{
    for (int i = x; i < n; i += x)
    {
        for (int j = 0; j < 26; j++)
        {
            if (t[i][j] - t[i - x][j] != t[i + x][j] - t[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            t[i][j] = t[i - 1][j];
        }
        t[i][s[i] - 'a']++;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            if (check(i))
            {
                for (int j = 1; j <= i; j++)
                {
                    printf("%c", s[j]);
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}