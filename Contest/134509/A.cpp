#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
const int MaxN = 1e4 + 5;
int n;
int copy;
char tmp[MaxN];
char cmd[MaxN];
char name[MaxN];
char string[MaxN];
std::unordered_map<std::string, int> name_list;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %s", cmd, tmp);
        int w;
        w = 0;
        for (;;)
        {
            if (tmp[w] == '(')
            {
                break;
            }
            name[w] = tmp[w];
            name[w + 1] = '\0';
            w++;
        }
        w++;
        int stop;
        stop = w;
        for (;;)
        {
            if (tmp[w] == ')')
            {
                break;
            }
            string[w - stop] = tmp[w];
            string[w - stop + 1] = '\0';
            w++;
        }
        if (strcmp(cmd, "string") == 0)
        {
            if (string[0] == '\"')
            {
                copy += strlen(string) - 2;
                name_list[name] = strlen(string) - 2;
            }
            else
            {
                copy += name_list[string];
                name_list[name] = name_list[string];
            }
        }
        else
        {
            if (string[0] == '\"')
            {
                name_list[name] = strlen(string) - 2;
            }
            else
            {
                name_list[name] = name_list[string];
            }
        }
        for (; false;)
        {
            ;
        }
    }
    printf("%d\n", copy);
    return 0;
}