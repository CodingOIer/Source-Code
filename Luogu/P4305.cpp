#include <cstdio>
#include <set>
const int MaxN = 5e4 + 5;
int t;
int n;
int x;
std::set<int> set;
void solve()
{
    set.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (set.find(x) == set.end())
        {
            printf("%d ", x);
        }
        set.insert(x);
    }
    printf("\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}