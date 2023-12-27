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
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int to = -1;
        for (int j = 0; j < (int)(desk.size()); j++)
        {
            if (desk[j] + p[i] <= m)
            {
                to = j;
            }
        }
    }
    return 0;
}