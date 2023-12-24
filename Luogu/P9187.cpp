#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
const int m = 1 << 18;
int n, c;
char opt;
int w;
int Q[MaxN], f[m];
queue<int> bfs;
signed main()
{
    scanf("%d%d", &c, &n);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        w = 0;
        for (int j = 0; j < c; ++j)
        {
            scanf("%c", &opt);
            w += (1 << j) * (opt == 'G');
        }
        Q[i] = (1 << c) - 1 - w;
        f[w] = 0;
        bfs.push(w);
    }
    for (; !bfs.empty();)
    {
        w = bfs.front();
        bfs.pop();
        for (int i = 0; i < c; ++i)
        {
            if (f[w ^ (1 << i)] > f[w] + 1)
            {
                f[w ^ (1 << i)] = f[w] + 1;
                bfs.push(w ^ (1 << i));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", c - f[Q[i]]);
    }
    return 0;
}