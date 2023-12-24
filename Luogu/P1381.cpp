#include <cstdio>
#include <map>
#include <string>
const int MaxN = 1e3 + 5;
int n;
char s[MaxN][15];
std::map<std::string, std::string> map;
int main()
{
    scanf("%n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i]);
    }
    return 0;
}