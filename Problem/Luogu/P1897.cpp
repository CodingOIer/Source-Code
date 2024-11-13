#include <cstdio>
#include <set>
constexpr int MaxN = 1e5 + 5;
int n;
std::set<long long> set;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        set.insert(x);
    }
    printf("%lld\n", 10ll * (*set.rbegin()) + 5ll * set.size() + n);
    return 0;
}