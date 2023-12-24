#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
const int MaxN = 2e6 + 5;
class pair
{
  public:
    int x;
    int time;
    bool operator<(const pair &__x) const
    {
        return (*this).x < __x.x;
    }
    bool operator>(const pair &__x) const
    {
        return (*this).x > __x.x;
    }
};
int n, m;
int p[MaxN];
std::priority_queue<pair, std::vector<pair>, std::greater<pair>> queue;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (; !queue.empty() && queue.top().time + m < i;)
        {
            queue.pop();
        }
        if (queue.empty())
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", queue.top().x);
        }
        pair t;
        t.time = i;
        t.x = p[i];
        queue.push(t);
    }
    return 0;
}