#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e6 + 5;
int n, m;
int p[MaxN];
int answer[MaxN];
long long tree[MaxN];
std::vector<std::tuple<int, int>> v[MaxN];
void change(int x, int val)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += val;
    }
}
long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= x & -x)
    {
        res += tree[x];
    }
    return res;
}
long long query(int l, int r)
{
    return query(r) - query(l - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        v[l - 1].push_back({x, -i});
        v[r].push_back({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        change(p[i], 1);
        for (const auto &[x, c] : v[i])
        {
            if (c < 0)
            {
                answer[-c] -= query(1, x);
            }
            else
            {
                answer[c] += query(1, x);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}