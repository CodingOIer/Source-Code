#include <cstdio>
#include <random>
std::mt19937_64 rnd(std::random_device{}());
int h, w;
int n, m;
long long k;
int main()
{
    scanf("%d%d%d%d", &h, &w, &n, &m);
    if (h % n == 0 && w % m == 0)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    k = rnd() % int(1e9 / (n * m) - 2) + 2;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (i % n == 0 && j % m == 0)
            {
                printf("%lld ", -((n * m - 1) * k + 1));
            }
            else
            {
                printf("%lld ", k);
            }
        }
        printf("\n");
    }
    return 0;
}
