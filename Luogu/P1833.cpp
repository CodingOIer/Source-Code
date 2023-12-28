#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e4 + 5;
constexpr int MaxM = 1e3 + 5;
class pair
{
  public:
    int cost;
    int value;
    pair()
    {
        cost = 0;
        value = 0;
    }
    pair(const int &__x, const int &__y)
    {
        cost = __x;
        value = __y;
    }
};
int k;
int n, m;
int dp[MaxM];
pair thing[20 * MaxN];
int main()
{
    int a, b, c, d;
    scanf("%d:%d %d:%d %d", &a, &b, &c, &d, &n);
    m = (c - a) * 60 + (d - b);
    for (int i = 1; i <= n; i++)
    {
        int t, c, p;
        scanf("%d%d%d", &t, &c, &p);
        if (p == 0)
        {
            p = 1e5;
        }
        int pow = 1;
        for (; p >= pow;)
        {
            p -= pow;
            k++;
            thing[k] = pair(t * pow, c * pow);
            pow *= 2;
        }
        if (p != 0)
        {
            k++;
            thing[k] = pair(t * p, c * p);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = m; j >= thing[i].cost; j--)
        {
            dp[j] = std::max(dp[j], dp[j - thing[i].cost] + thing[i].value);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}