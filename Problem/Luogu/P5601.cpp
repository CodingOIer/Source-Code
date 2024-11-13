#include <cstdio>
#include <map>
#include <string>
constexpr int MaxN = 1e2 + 5;
int n, m;
char s[MaxN];
char a[MaxN];
char b[MaxN];
char c[MaxN];
char d[MaxN];
std::map<std::string, std::string> map;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf(" ");
        scanf("%s", s);
        scanf(" ");
        scanf("%s", a);
        map[s] = a;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf(" ");
        scanf("%s", s);
        scanf(" ");
        scanf("%s", a);
        scanf(" ");
        scanf("%s", b);
        scanf(" ");
        scanf("%s", c);
        scanf(" ");
        scanf("%s", d);
        if (map[s] == a)
        {
            printf("A\n");
        }
        if (map[s] == b)
        {
            printf("B\n");
        }
        if (map[s] == c)
        {
            printf("C\n");
        }
        if (map[s] == d)
        {
            printf("D\n");
        }
    }
    return 0;
}