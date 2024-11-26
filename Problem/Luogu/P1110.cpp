#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
constexpr int MaxN = 5e5 + 5;
constexpr int MaxM = 1e2 + 5;
int n, m;
char op[MaxM];
std::vector<long long> v[MaxN];
std::multiset<long long> set;
std::multiset<long long> all;
std::multiset<long long> minAnswer;
long long abs(long long x)
{
    return x < 0 ? -x : x;
}
int main()
{
    scanf("%d%d", &n, &m);
    v[n + 1].push_back(-0x7f7f7f7f);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v[i].push_back(x);
    }
    set.insert(0x7f7f7f7f);
    all.insert(0x7f7f7f7f);
    all.insert(-0x7f7f7f7f);
    minAnswer.insert(2ll * 0x7f7f7f7f);
    for (int i = 1; i <= n; i++)
    {
        set.insert(abs(v[i][0] - v[i + 1][0]));
        auto itl = all.upper_bound(v[i][0]);
        auto itr = itl;
        itl--;
        minAnswer.erase(minAnswer.find(abs(*itl - *itr)));
        minAnswer.insert(abs(*itl - v[i][0]));
        minAnswer.insert(abs(*itr - v[i][0]));
        all.insert(v[i][0]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf(" ");
        scanf("%s", op);
        if (strcmp(op, "INSERT") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            set.erase(set.find(abs(*v[x].rbegin() - *v[x + 1].begin())));
            set.insert(abs(*v[x].rbegin() - y));
            set.insert(abs(*v[x + 1].begin() - y));
            auto itl = all.upper_bound(y);
            auto itr = itl;
            itl--;
            minAnswer.erase(minAnswer.find(abs(*itl - *itr)));
            minAnswer.insert(abs(*itl - y));
            minAnswer.insert(abs(*itr - y));
            all.insert(y);
            v[x].push_back(y);
        }
        if (strcmp(op, "MIN_GAP") == 0)
        {
            printf("%lld\n", *set.begin());
        }
        if (strcmp(op, "MIN_SORT_GAP") == 0)
        {
            printf("%lld\n", *minAnswer.begin());
        }
    }
    return 0;
}
