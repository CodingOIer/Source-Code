#include <cstdio>
#include <map>
#include <string>
int n;
char s[15];
std::map<std::string, bool> map;
std::map<std::string, bool> cnt;
int main()
{
    scanf("%n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        map[s] = true;
    }
    return 0;
}