#include <algorithm>
#include <cstdio>
#include <vector>
int n, m;
std::vector<int> v;
std::vector<std::vector<int>> answer;
void dfs(int u, int pre)
{
    if (u == n + 1)
    {
        answer.push_back(v);
        return;
    }
    if ((m - pre) / (n - u + 1) < 10)
    {
        return;
    }
    for (int i = std::max(1, pre + 10); i <= m; i++)
    {
        v.push_back(i);
        dfs(u + 1, i);
        v.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    dfs(1, -0x7f7f7f7f);
    printf("%zu\n", answer.size());
    for (const auto &v : answer)
    {
        for (const auto &val : v)
        {
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
