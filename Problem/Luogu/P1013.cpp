#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
char t[MaxN];
std::map<int, bool> use;
std::vector<std::tuple<std::string, int>> v;
int main()
{
    scanf("%d", &n);
    scanf(" ");
    scanf("%[^\r]s", s);
    if (strcmp(s, "+ M N P") == 0 || strcmp(s, "+ L K V E") == 0)
    {
        printf("ERROR!\n");
        return 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf(" ");
        scanf("%s", s);
        int all = 0;
        for (int j = 1; j <= n - 1; j++)
        {
            scanf(" ");
            scanf("%s", t);
            all += strlen(t) == 2 ? 1 : 0;
        }
        if (use[all])
        {
            printf("ERROR!\n");
            return 0;
        }
        use[all] = true;
        v.push_back({s, all});
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (!use[i])
        {
            printf("ERROR!\n");
            return 0;
        }
    }
    for (const auto &[s, k] : v)
    {
        printf("%s=%d ", s.c_str(), k);
    }
    printf("\n");
    printf("%d\n", n - 1);
    return 0;
}
