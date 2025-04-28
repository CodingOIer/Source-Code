#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n, m;
char s[MaxN];
char t[MaxN];
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i + m - 1 <= n; ++i)
    {
        bool suc = true;
        for (int j = 0; j < m; ++j)
        {
            suc &= s[i + j] == '?' || s[i + j] == t[j + 1];
        }
        if (suc)
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}