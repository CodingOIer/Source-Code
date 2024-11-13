#include <cstdio>
#include <cstring>
#include <set>
const int MaxN = 2e3 + 5;
const int Mod = 1e9 + 21;
int n;
char s[MaxN];
std::set<int> set;
int hash(char s[])
{
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = (res * 128) % Mod + s[i];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        set.insert(hash(s));
    }
    printf("%d\n", set.size());
    return 0;
}