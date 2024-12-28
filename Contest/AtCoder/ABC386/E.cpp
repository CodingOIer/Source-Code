#include <algorithm>
#include <cstdio>
#include <ctime>
constexpr int MaxN = 2e5 + 5;
int n, k;
long long temp;
long long answer;
long long p[MaxN];
void dfs(int u, int cur)
{
    if (u > k)
    {
        answer = std::max(answer, temp);
        return;
    }
    for (int i = cur; i <= n - (k - u); i++)
    {
        temp ^= p[i];
        dfs(u + 1, i + 1);
        temp ^= p[i];
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    bool rev = false;
    if (k > n / 2)
    {
        k = n - k;
        rev = true;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        if (rev)
        {
            temp ^= p[i];
        }
    }
    dfs(1, 1);
    printf("%lld\n", answer);
    return 0;
}
