#include <cstdio>
#include <ctime>
#include <utility>
#include <vector>
int x;
int still;
std::vector<int> use;
std::vector<std::pair<int, int>> cnt;
long long fsp(long long x, long long y)
{
    long long res = 1;
    for (; y > 0;)
    {
        if (y % 2 == 1)
        {
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}
int main()
{
    scanf("%d", &x);
    int more = 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int b = x;
            int temp = 0;
            for (; x % i == 0;)
            {
                x /= i;
                temp++;
            }
            use.push_back(0);
            cnt.push_back({temp, i});
            more += temp > 1 ? 1 : 0;
        }
    }
    if (x != 1)
    {
        use.push_back(0);
        cnt.push_back({1, x});
    }
    int l = cnt.size();
    if (l != 1 && (l % 2 == 0 || (l % 2 == 1 && more > 0)))
    {
        printf("%lld\n", 1ll);
    }
    else
    {
        printf("%lld\n", fsp(cnt[0].second, cnt[0].first));
    }
    return 0;
}