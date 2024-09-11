#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200005;

vector<int> adj[MaxN];
vector<pair<int, int>> q[MaxN];
int ans[MaxN];
bool visited[MaxN];

void dfs(int u, int par, int xor_val)
{
    visited[u] = true;
    ans[u] = xor_val;

    for (auto query : q[u])
    {
        int v = query.first;
        int x = query.second;

        ans[u] ^= x;

        if (visited[v])
        {
            ans[u] ^= ans[v];
        }
    }

    for (int v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u, ans[u]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int qn;
    cin >> qn;

    for (int i = 0; i < qn; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        q[u].push_back({v, x});
        q[v].push_back({u, x});
    }

    // Perform DFS on tree starting from root 1
    dfs(1, -1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}