#include <cstdio>
#include <set>
constexpr int MaxN = 1e2 + 5;
int n, k;
char s[MaxN];
std::set<int> set;
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '@')
        {
            set.insert(i);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        set.erase(*set.rbegin());
    }
    for (int i = 1; i <= n; i++)
    {
        if (set.lower_bound(i) != set.end() && *set.lower_bound(i) == i)
        {
            printf("@");
        }
        else
        {
            printf(".");
        }
    }
    printf("\n");
    return 0;
}
