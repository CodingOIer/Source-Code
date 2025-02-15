#include <bitset>
#include <cstdio>
constexpr int MaxN = 4e3 + 5;
int n;
int p[MaxN];
void solve()
{
    scanf("%d", &n);
    std::bitset<MaxN> can;
    int begin = -1;
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &p[i]);
        if (begin == -1)
        {
            begin = i;
        }
        else if (p[begin] < p[i])
        {
            can |= (can << (i - begin));
            can[i - begin] = true;
            begin = i;
        }
    }
    printf("%s\n", can[n] ? "YES" : "NO");
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
