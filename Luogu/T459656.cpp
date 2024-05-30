#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
long long tree[MaxN];
std::vector<std::pair<int, int>> v;
inline void change(int x, int v)
{
    for (; x <= n; x += x & -x)
    {
        tree[x] += v;
    }
}
inline long long query(int x)
{
    long long res = 0;
    for (; x > 0; x += x & -x)
    {
        res += tree[x];
    }
    return res;
}
inline long long query(int l, int r)
{
    return query(r) - query(l - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        v.push_back({p[i], i});
    }
    std::sort(v.begin(), v.end());
    auto it = v.begin();
    for (int i = 1; i <= n; i++)
    {
        change(i, i - 1);
    }
    long long answer = 0;
    for (int j = 0; j < n; j++)
    {
        for (; it != v.end() && (*it).first < j;)
        {
        }
        printf("%lld\n", answer);
    }
    return 0;
}