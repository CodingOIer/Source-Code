#include <cstdio>
#include <map>
#include <string>
const int MaxN = 5e1 + 5;
int n, m;
char s[MaxN];
std::map<std::string, int> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &s);
        map[s] = 1;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", &s);
        if (map[s] == 1)
        {
            printf("OK\n");
            map[s] = 2;
        }
        else if (map[s] == 0)
        {
            printf("WRONG\n");
        }
        else
        {
            printf("REPEAT\n");
        }
    }
    return 0;
}