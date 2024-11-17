#include <cstdio>
#include <set>
#include <tuple>
constexpr int MaxN = 5e5 + 5;
int n, q;
int cnt[MaxN];
std::set<std::tuple<int, int, int>> set;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        set.insert({i, i, i});
        cnt[i] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, c;
            scanf("%d%d", &x, &c);
            auto it = set.upper_bound({x, 0x3f3f3f3f, 0x3f3f3f3f});
            it--;
            int l, r, co;
            std::tie(l, r, co) = *it;
            cnt[co] -= r - l + 1;
            cnt[c] += r - l + 1;
            bool rl, rr;
            rl = rr = false;
            if (it != set.begin())
            {
                it--;
                int l2, r2, co2;
                std::tie(l2, r2, co2) = *it;
                if (co2 == c)
                {
                    rl = true;
                    l = l2;
                }
                it++;
            }
            it++;
            if (it != set.end())
            {
                int l2, r2, co2;
                std::tie(l2, r2, co2) = *it;
                if (co2 == c)
                {
                    rr = true;
                    r = r2;
                }
            }
            it--;
            if (rl)
            {
                it = set.upper_bound({x, 0x3f3f3f3f, 0x3f3f3f3f});
                it--;
                it--;
                set.erase(it);
            }
            if (rr)
            {
                it = set.upper_bound({x, 0x3f3f3f3f, 0x3f3f3f3f});
                set.erase(it);
            }
            it = set.upper_bound({x, 0x3f3f3f3f, 0x3f3f3f3f});
            it--;
            set.erase(it);
            set.insert({l, r, c});
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", cnt[x]);
        }
    }
    return 0;
}
