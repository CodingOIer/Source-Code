#include <algorithm>
#include <cstdio>
#include <vector>
const int MaxN = 25;
int n, m;
int p[MaxN];
std::vector<int> desk;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, [](const int &__x, const int &__y) { return __x > __y; });
    for (int i = 1; i <= n; i++)
    {
        int to = -1;
        for (int j = 0; j < (int)(desk.size()); j++)
        {
            if (desk[j] + p[i] <= m)
            {
                to = j;
                break;
            }
        }
        if (to == -1)
        {
            desk.push_back(p[i]);
        }
        else
        {
            desk[to] += p[i];
        }
        std::sort(desk.begin(), desk.end(), [](const int &__x, const int &__y) { return __x > __y; });
    }
    printf("%d\n", (int)(desk.size()));
    return 0;
}