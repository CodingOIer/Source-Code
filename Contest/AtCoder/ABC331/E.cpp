#include <algorithm>
#include <cstdio>
#include <map>
constexpr int MaxN = 1e5 + 5;
class meal
{
  public:
    int id, money;
};
int answer;
int n, m, l;
meal a[MaxN];
meal b[MaxN];
std::map<std::pair<int, int>, bool> state;
int main()
{
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].money);
        a[i].id = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i].money);
        b[i].id = i;
    }
    for (int i = 1; i <= l; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        state[{u, v}] = true;
    }
    std::sort(a + 1, a + n + 1, [](const meal &x, const meal &y) { return x.money > y.money; });
    std::sort(b + 1, b + m + 1, [](const meal &x, const meal &y) { return x.money > y.money; });
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i].money + b[j].money < answer)
            {
                break;
            }
            if (state[{a[i].id, b[j].id}])
            {
                continue;
            }
            else
            {
                answer = std::max(answer, a[i].money + b[j].money);
                break;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}