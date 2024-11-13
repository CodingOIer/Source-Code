#include <algorithm>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <numeric>
#include <random>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 5e1 + 5;
int n;
int p[MaxN];
std::bitset<MaxN> f[MaxN];
int main()
{
    scanf("%d", &n);
    for (int x, y; scanf("%d%d", &x, &y) == 2;)
    {
        f[x][y] = true;
        f[y][x] = true;
    }
    int answer = 0;
    std::iota(p + 1, p + 1 + n, 1);
    for (; double(clock()) / CLOCKS_PER_SEC <= 0.985;)
    {
        std::shuffle(p + 1, p + 1 + n, rnd);
        std::bitset<MaxN> ck;
        ck.set();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ck[p[i]])
            {
                cnt++;
                ck &= f[p[i]];
            }
        }
        answer = std::max(answer, cnt);
    }
    printf("%d\n", answer);
    return 0;
}