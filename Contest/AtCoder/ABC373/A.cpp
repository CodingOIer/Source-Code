#include <cstdio>
#include <cstring>
#include <map>
constexpr int MaxN = 1e2 + 5;
char s[MaxN];
std::map<int, int> map;
int main()
{
    int r = 0;
    for (int i = 1; i <= 12; i++)
    {
        scanf("%s", s);
        if (strlen(s) == i)
        {
            r++;
        }
    }
    printf("%d\n", r);
    return 0;
}