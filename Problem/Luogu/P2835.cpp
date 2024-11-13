#include <cstdio>
#include <vector>
constexpr int MaxN = 2e2 + 5;
int n;
int answer;
int manger[MaxN];
bool vis[MaxN];
bool temp[MaxN];
std::vector<int> link[MaxN];
void dfs(int x, int top)
{
    if (manger[x] == top)
    {
        return;
    }
    manger[x] = top;
    for (auto next : link[x])
    {
        dfs(next, top);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        for (; x != 0;)
        {
            link[i].push_back(x);
            scanf("%d", &x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (manger[i] == 0)
        {
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (temp[manger[i]] == false)
        {
            answer++;
            temp[manger[i]] = true;
        }
    }
    printf("%d\n", answer);
    return 0;
}