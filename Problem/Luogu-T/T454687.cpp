#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, k;
long long m;
std::vector<long long> v;
bool update(long long w)
{
    std::vector<long long> p;
    std::vector<long long> b = v;
    for (auto x : v)
    {
        p.push_back(w - ((x - 1) % w + 1));
    }
    v.clear();
    long long kl = 0;
    std::sort(p.begin(), p.end());
    for (int i = 0; i < p.size() && (v.size() < k || p[i] == 0); i++)
    {
        kl += p[i];
        v.push_back(p[i]);
    }
    if (kl <= m && v.size() >= k)
    {
        m -= kl;
        return true;
    }
    else
    {
        v = b;
        return false;
    }
}
int main()
{
    scanf("%d%lld%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        v.push_back(x);
    }
    long long answer = 0;
    for (int j = 40; j >= 0; j--)
    {
        printf("%d\n", j);
        if (update(1ll << j) && v.size() >= k)
        {
            answer += (1ll << j);
        }
    }
    printf("%lld\n", answer);
    return 0;
}