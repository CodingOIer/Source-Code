#include <cstdio>
#include <set>
constexpr int MaxN = 1e2 + 5;
int t;
int n;
int p[MaxN];
std::multiset<int> set;
void solve()
{
    scanf("%d", &n);
    set.clear();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int k = 1; k <= n; k++)
    {
        set.clear();
        for (int i = 1; i <= n; i++)
        {
            set.insert(p[i]);
        }
        int accept = true;
        for (int i = 1; i <= k; i++)
        {
            for (; !set.empty() && !(*set.rbegin() <= k - i + 1);)
            {
                set.erase(*set.rbegin());
            }
            if (set.empty())
            {
                accept = false;
                break;
            }
            set.erase(set.find(*set.rbegin()));
            if (set.empty())
            {
                if (i == k)
                {
                    break;
                }
                else
                {
                    accept = false;
                    break;
                }
            }
            set.erase(set.find(*set.begin()));
        }
        if (!accept)
        {
            printf("%d\n", k - 1);
            return;
        }
    }
    printf("%d\n", n);
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