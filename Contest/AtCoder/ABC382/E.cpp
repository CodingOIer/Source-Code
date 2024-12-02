#include <cstdio>
#include <ctime>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e3 + 5;
int n, x;
int p[MaxN];
int tryOpen()
{
    int have = 0;
    int opened = 0;
    for (; have < x;)
    {
        opened++;
        for (int i = 1; i <= n; i++)
        {
            if (int(rnd() % 100 + 1) <= p[i])
            {
                have++;
            }
        }
    }
    return opened;
}
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    long long cnt = 0;
    long long have = 0;
    for (; double(clock()) / CLOCKS_PER_SEC <= 1.99;)
    {
        have += tryOpen();
        cnt++;
    }
    printf("%.12lf\n", 1.0 * have / cnt);
    return 0;
}
