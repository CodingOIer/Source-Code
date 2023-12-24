#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int n;
int answer;
std::vector<int> son;
std::vector<int> link[MaxN];
int dfs(int root, int last)
{
    int res = 1;
    for (int next : link[root])
    {
        if (next == last)
        {
            continue;
        }
        res += dfs(next, root);
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    for (int next : link[1])
    {
        son.push_back(dfs(next, 1));
    }
    std::sort(son.begin(), son.end());
    for (int i = 0; i < (int)(son.size()) - 1; i++)
    {
        answer += son[i];
    }
    printf("%d\n", answer + 1);
    return 0;
}