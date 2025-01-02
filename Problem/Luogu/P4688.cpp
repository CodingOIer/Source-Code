#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <tuple>
#include <vector>
class ask
{
  public:
    int l, r, id;
    ask()
    {
    }
};
constexpr int MaxN = 1e5 + 5;
constexpr int SubtaskSize = 1e2 + 5;
int n, m;
int p[MaxN];
int l1[MaxN];
int r1[MaxN];
int l2[MaxN];
int r2[MaxN];
int l3[MaxN];
int r3[MaxN];
std::vector<int> uq;
std::bitset<MaxN> f[SubtaskSize * 3];
std::vector<std::tuple<int, int, int>> v;
void initMo()
{
    int block = sqrt(v.size());
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        uq.push_back(p[i]);
    }
    std::sort(uq.begin(), uq.end());
    uq.erase(std::unique(uq.begin(), uq.end()), uq.end());
    for (int i = 1; i <= n; i++)
    {
        p[i] = std::lower_bound(uq.begin(), uq.end(), p[i]) - uq.begin() + 1;
    }
    int calcPre = 1;
    for (int i = 1; i <= m; i++)
    {
        v.push_back({l1[i], r1[i], i * 3 - 2});
        v.push_back({l2[i], r2[i], i * 3 - 1});
        v.push_back({l3[i], r3[i], i * 3 - 0});
        if (i - calcPre + 1 >= SubtaskSize)
        {
        }
    }
    return 0;
}
