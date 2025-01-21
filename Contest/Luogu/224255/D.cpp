#include <cstdio>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
int p[MaxN];
std::vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] <= 15)
        {
            v.push_back(p[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > 15)
        {
            v.push_back({p[i]});
        }
    }
    for (const auto &val : v)
    {
        printf("%d ", val);
    }
    return 0;
}
