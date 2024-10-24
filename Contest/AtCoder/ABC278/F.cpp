#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <tuple>
constexpr int MaxN = 1e2 + 5;
int n;
char bg[MaxN];
char ed[MaxN];
char temp[MaxN];
std::map<std::tuple<int, char>, bool> map;
bool win(int status, char last)
{
    if (map.count({status, last}))
    {
        return map[{status, last}];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((~status >> (i - 1)) & 1 && (status == 0 || bg[i] == last) && !win(status | (1 << (i - 1)), ed[i]))
        {
            map[{status, last}] = true;
            return true;
        }
    }
    map[{status, last}] = false;
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", temp + 1);
        bg[i] = temp[1];
        ed[i] = temp[strlen(temp + 1)];
    }
    printf("%s\n", win(0, '\0') ? "First" : "Second");
    return 0;
}