#include <cstdio>
#include <map>
#include <set>
std::set<int> set;
std::map<int, int> map;
int main()
{
    for (;;)
    {
        int op;
        scanf("%d", &op);
        if (op == -1)
        {
            break;
        }
        switch (op)
        {
        case 1:
            int w, c;
            scanf("%d%d", &w, &c);
            if (set.find(c) != set.end())
            {
                break;
            }
            set.insert(c);
            map[c] = w;
            break;
        case 2:
            if (!set.empty())
            {
                set.erase(*set.rbegin());
            }
            break;
        case 3:
            if (!set.empty())
            {
                set.erase(*set.begin());
            }
            break;
        }
    }
    long long cost, beau;
    cost = beau = 0;
    for (auto x : set)
    {
        cost += x;
        beau += map[x];
    }
    printf("%lld %lld\n", beau, cost);
    return 0;
}