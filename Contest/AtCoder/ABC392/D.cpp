#include <algorithm>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
constexpr int MaxN = 1e2 + 5;
int n;
int k[MaxN];
gp_hash_table<int, int> map[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
        {
            int x;
            scanf("%d", &x);
            map[i][x]++;
        }
    }
    double answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (map[i].size() < map[j].size())
            {
                double temp = 0;
                for (const auto &[color, cnt] : map[i])
                {
                    temp += (1.0 * cnt / k[i]) * (1.0 * map[j][color] / k[j]);
                }
                answer = std::max(answer, temp);
            }
            else
            {
                double temp = 0;
                for (const auto &[color, cnt] : map[j])
                {
                    temp += (1.0 * map[i][color] / k[i]) * (1.0 * cnt / k[j]);
                }
                answer = std::max(answer, temp);
            }
        }
    }
    printf("%.12lf\n", answer);
    return 0;
}
