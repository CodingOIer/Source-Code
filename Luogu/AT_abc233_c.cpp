#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int answer;
long long x;
std::vector<int> v[MaxN];
void solve(int w, long long all)
{
    if (w == n + 1)
    {
        answer += all == x ? 1 : 0;
        return;
    }
    for (auto i : v[w])
    {
        if (all > x / i)
        {
            continue;
        }
        solve(w + 1, all * i);
    }
}
int main()
{
    scanf("%d%lld", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        int l;
        scanf("%d", &l);
        for (int j = 1; j <= l; j++)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    solve(1, 1);
    printf("%d\n", answer);
    return 0;
}