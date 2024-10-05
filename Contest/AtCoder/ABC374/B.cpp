#include <algorithm>
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
    if (strcmp(s + 1, t + 1) == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 1; i <= std::max(n, m); i++)
        {
            if (s[i] != t[i])
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}