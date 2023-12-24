#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
const int MaxN = 2e5 + 5;
const int MaxM = 1e1 + 5;
class str
{
  public:
    std::string s;
    int k;
};
int n;
int cnt;
str sort[MaxN];
char s[MaxN][MaxM];
std::map<std::string, int> map;
std::map<std::string, int> vis;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i]);
        map[s[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[s[i]])
        {
            continue;
        }
        vis[s[i]] = true;
        cnt++;
        sort[cnt].s = s[i];
        sort[cnt].k = map[s[i]];
    }
    std::sort(sort + 1, sort + 1 + n, [](str a, str b) { return (a.k > b.k) || (a.k == b.k && a.s < b.s); });
    for (int i = 1; i <= cnt; i++)
    {
        if (i != 1 && sort[i].k < sort[i - 1].k)
        {
            break;
        }
        printf("%s\n", sort[i].s.c_str());
    }
    return 0;
}