#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;

int MaxN, m, K;
int u[MAXN], v[MAXN], w[MAXN];
int G[MAXN][MAXN];
int visited[MAXN];
long long ans;

void dfs(int u, int fa)
{
    visited[u] = 1;
    for (int i = 1; i <= MaxN; i++)
    {
        if (i != fa && G[u][i] != 0)
        {
            ans += G[u][i];
            dfs(i, u);
        }
    }
}

int main()
{
    cin >> MaxN >> m >> K;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        G[u[i]][v[i]] = G[v[i]][u[i]] = (w[i] % K + K) % K;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}