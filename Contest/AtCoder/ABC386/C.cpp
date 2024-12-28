#include <cstdio>
#include <cstring>
#include <utility>
constexpr int MaxN = 5e5 + 5;
int n, m;
char s[MaxN];
char t[MaxN];
int main()
{
    scanf("%*d");
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    if (n == m)
    {
        bool diff = false;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] != t[i])
            {
                if (diff)
                {
                    printf("No\n");
                    return 0;
                }
                diff = true;
            }
        }
        printf("Yes\n");
    }
    else
    {
        char *a;
        char *b;
        a = s;
        b = t;
        if (n < m)
        {
            std::swap(a, b);
            std::swap(n, m);
        }
        if (n - m != 1)
        {
            printf("No\n");
            return 0;
        }
        int j = 0;
        bool skip = false;
        for (int i = 1; i <= n; i++)
        {
            j++;
            if (a[i] != b[j])
            {
                if (skip)
                {
                    printf("No\n");
                    return 0;
                }
                skip = true;
                j--;
            }
        }
        printf("Yes\n");
    }
    return 0;
}
