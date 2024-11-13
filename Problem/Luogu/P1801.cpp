#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
const int MaxN = 2e5 + 5;
int m, n;
int add[MaxN];
int get[MaxN];
std::priority_queue<int, std::vector<int>, std::less<int>> small;
std::priority_queue<int, std::vector<int>, std::greater<int>> black_box;
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &add[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &get[i]);
    }
    int j;
    j = 1;
    for (int i = 1; i <= n; i++)
    {
        for (; j <= get[i]; j++)
        {
            small.push(add[j]);
            black_box.push(small.top());
            small.pop();
        }
        printf("%d\n", black_box.top());
        small.push(black_box.top());
        black_box.pop();
    }
    return 0;
}