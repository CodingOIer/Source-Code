#include <algorithm>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int n, m;
char want[MaxN];
char s[MaxN][MaxN];
bool vis[MaxN][MaxN];
std::vector<int> answer;
inline bool checkR(int x, int y, int k)
{
    if (!(1 <= x && x + k - 1 <= n && 1 <= y && y <= m))
    {
        return false;
    }
    for (int j = 0; j < k; j++)
    {
        if (s[x + j][y] != want[j + 1] || vis[x + j][y])
        {
            return false;
        }
    }
    for (int j = 0; j < k; j++)
    {
        vis[x + j][y] = true;
    }
    return true;
}
inline bool checkC(int x, int y, int k)
{
    if (!(1 <= x && x <= n && 1 <= y && y + k - 1 <= m))
    {
        return false;
    }
    for (int j = 0; j < k; j++)
    {
        if (s[x][y + j] != want[j + 1] || vis[x][y + j])
        {
            return false;
        }
    }
    for (int j = 0; j < k; j++)
    {
        vis[x][y + j] = true;
    }
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int k = 1; k <= std::max(n, m); k++)
    {
        if (n % k == 0 || m % k == 0)
        {
            bool f = false;
            if (k <= m && !f)
            {
                f = true;
                memset(vis, false, sizeof(vis));
                for (int i = 1; i <= k; i++)
                {
                    want[i] = s[1][i];
                    want[i + 1] = '\0';
                }
                for (int i = 1; i <= n && f; i++)
                {
                    for (int j = 1; j <= m && f; j++)
                    {
                        if (vis[i][j])
                        {
                            continue;
                        }
                        if (!checkC(i, j, k))
                        {
                            if (!checkR(i, j, k))
                            {
                                f = false;
                            }
                        }
                    }
                }
                if (f)
                {
                    answer.push_back(k);
                }
            }
            if (k <= n && !f)
            {
                f = true;
                memset(vis, false, sizeof(vis));
                for (int i = 1; i <= k; i++)
                {
                    want[i] = s[i][1];
                    want[i + 1] = '\0';
                }
                bool f = true;
                for (int i = 1; i <= n && f; i++)
                {
                    for (int j = 1; j <= m && f; j++)
                    {
                        if (vis[i][j])
                        {
                            continue;
                        }
                        if (!checkC(i, j, k))
                        {
                            if (!checkR(i, j, k))
                            {
                                f = false;
                            }
                        }
                    }
                }
                if (f)
                {
                    answer.push_back(k);
                }
            }
        }
    }
    printf("%zu\n", answer.size());
    for (auto val : answer)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}