#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
const int MaxN = 1e5 + 5;
int n, m;
int in[MaxN];
int out[MaxN];
int last[MaxN];
std::stack<int> answer;
std::vector<int> link[MaxN];
void dfs(int x)
{
    for (int i = last[x]; i < link[x].size(); i = last[x])
    {
        last[x] = i + 1;
        dfs(link[x][i]);
    }
    answer.push(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        link[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        std::sort(link[i].begin(), link[i].end());
    }
    int first = 1;
    bool back, start, end;
    back = true;
    start = false;
    end = false;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] != out[i])
        {
            back = false;
        }
        if (in[i] == out[i] + 1)
        {
            if (end)
            {
                printf("No\n");
                return 0;
            }
            end = true;
        }
        if (out[i] == in[i] + 1)
        {
            if (start)
            {
                printf("No\n");
                return 0;
            }
            first = i;
            start = true;
        }
    }
    if (!back && !(start == 1 && end == 1))
    {
        printf("No\n");
        return 0;
    }
    dfs(first);
    for (; !answer.empty();)
    {
        printf("%d ", answer.top());
        answer.pop();
    }
    printf("\n");
    return 0;
}