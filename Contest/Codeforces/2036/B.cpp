#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, k;
int b[MaxN];
int c[MaxN];
std::vector<int> v;
std::map<int, int> map;
inline void solve()
{
    v.clear();
    map.clear();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &b[i], &c[i]);
        map[b[i]] += c[i];
    }
    for (auto k : map)
    {
        v.push_back(k.second);
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    int answer = 0;
    for (int i = 1; i <= std::min(n, int(v.size())); i++)
    {
        answer += v[i - 1];
    }
    printf("%d\n", answer);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}