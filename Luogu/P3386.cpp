#include <cstdio>
#include <random>
#include <vector>
const int MaxN = 5e2 + 5;
const int MaxE = 5e4 + 5;
int flag;
int answer;
int n, m, e;
int use[MaxN];
int solving[MaxN];
std::vector<int> link[MaxN];
std::mt19937 rnd(std::random_device{}());
bool solve(int x)
{
    if (solving[x] == flag)
    {
        return false;
    }
    solving[x] = flag;
    for (int to : link[x])
    {
        if (use[to] == 0)
        {
            use[to] = x;
            return true;
        }
        if (solve(use[to]))
        {
            use[to] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        flag = rnd();
        answer += solve(i) ? 1 : 0;
    }
    printf("%d\n", answer);
    return 0;
}