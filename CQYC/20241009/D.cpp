// 100
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <random>
#include <tuple>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 4e2 + 5;
constexpr int MaxK = 6e1 + 5;
int n, m, k;
int x[MaxN];
int y[MaxN];
int group[MaxN];
int score[MaxN];
char s[MaxN][MaxN];
bool vis[MaxK][MaxN][MaxN];
unsigned long long sha[MaxN];
unsigned long long charId[128];
unsigned long long find[MaxN][MaxN];
std::vector<int> gp[MaxN];
inline bool check(int x, int y)
{
    if (!(1 <= x && x <= n && 1 <= y && y <= m))
    {
        return false;
    }
    if (s[x][y] == 'X' || s[x][y] == '#')
    {
        return false;
    }
    return true;
}
inline unsigned long long getStatus(int x, int y)
{
    return (123456789ull * find[x - 1][y - 1] + 234567891ull * find[x - 1][y + 0] + 345678912ull * find[x - 1][y + 1]) +
           (456789123ull * find[x + 0][y - 1] + 567891234ull * find[x + 0][y + 0] + 678912345ull * find[x + 0][y + 1]) +
           (789123456ull * find[x + 1][y - 1] + 891234567ull * find[x + 1][y + 0] + 912345678ull * find[x + 1][y + 1]);
}
void solve(std::vector<std::tuple<int, int, int>> &v)
{
    int bid, bx, by;
    std::tie(bid, bx, by) = *v.begin();
    if (v.size() == 1)
    {
        group[bid] = bid;
        return;
    }
    std::queue<std::tuple<int, int>> queue;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[bid][i][j] &&
                (vis[bid][i + 1][j] || vis[bid][i - 1][j] || vis[bid][i][j + 1] || vis[bid][i][j - 1]))
            {
                queue.push(std::tuple<int, int>{i - bx, j - by});
            }
        }
    }
    if (queue.empty())
    {
        queue.push(std::tuple<int, int>{0, 0});
    }
    std::vector<unsigned long long> temp;
    for (; !queue.empty();)
    {
        int px, py;
        std::tie(px, py) = queue.front();
        queue.pop();
        if (vis[bid][bx + px][by + py])
        {
            continue;
        }
        bool can = true;
        for (auto _ : v)
        {
            int id, x, y;
            std::tie(id, x, y) = _;
            can &= check(x + px, y + py);
        }
        if (!can)
        {
            continue;
        }
        temp.clear();
        for (auto _ : v)
        {
            int id, x, y;
            std::tie(id, x, y) = _;
            vis[id][x + px][y + py] = true;
            sha[id] = getStatus(x + px, y + py);
            temp.push_back(sha[id]);
        }
        std::sort(temp.begin(), temp.end());
        temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
        if (int(temp.size()) == 1)
        {
            queue.push(std::tuple<int, int>{px + 1, py});
            queue.push(std::tuple<int, int>{px - 1, py});
            queue.push(std::tuple<int, int>{px, py + 1});
            queue.push(std::tuple<int, int>{px, py - 1});
            continue;
        }
        std::map<unsigned long long, std::vector<std::tuple<int, int, int>>> nv;
        for (auto _ : v)
        {
            int id, x, y;
            std::tie(id, x, y) = _;
            nv[sha[id]].push_back(std::tuple<int, int, int>{id, x, y});
        }
        for (auto sh : temp)
        {
            solve(nv[sh]);
        }
        return;
    }
    for (auto _ : v)
    {
        int id, x, y;
        std::tie(id, x, y) = _;
        group[id] = bid;
    }
}
void bfs(int gid)
{
    int bx, by;
    bx = x[gp[gid][0]];
    by = y[gp[gid][0]];
    std::queue<std::tuple<int, int>> queue;
    queue.push(std::tuple<int, int>{0, 0});
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            vis[0][i][j] = false;
        }
    }
    for (; !queue.empty();)
    {
        int px, py;
        std::tie(px, py) = queue.front();
        queue.pop();
        if (vis[0][bx + px][by + py])
        {
            continue;
        }
        vis[0][bx + px][by + py] = true;
        bool can = true;
        for (auto id : gp[gid])
        {
            can &= check(x[id] + px, y[id] + py);
        }
        if (!can)
        {
            continue;
        }
        for (auto id : gp[gid])
        {
            score[id] += s[x[id] + px][y[id] + py] == 'o' ? 1 : 0;
        }
        queue.push(std::tuple<int, int>{px + 1, py});
        queue.push(std::tuple<int, int>{px - 1, py});
        queue.push(std::tuple<int, int>{px, py + 1});
        queue.push(std::tuple<int, int>{px, py - 1});
    }
}
int main()
{
    unsigned long long sha1, sha2, sha3;
    sha1 = rnd();
    sha2 = rnd();
    sha3 = rnd();
    charId['S'] = sha1;
    charId['X'] = sha1;
    charId['.'] = sha1;
    charId['o'] = sha2;
    charId['#'] = sha3;
    scanf("%d%d", &n, &m);
    std::vector<std::tuple<int, int, int>> queue;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == 'S')
            {
                k++;
                x[k] = i;
                y[k] = j;
                queue.push_back(std::tuple<int, int, int>{k, i, j});
            }
            find[i][j] = charId[int(s[i][j])];
        }
    }
    solve(queue);
    std::vector<int> v;
    for (int i = 1; i <= k; i++)
    {
        gp[group[i]].push_back(i);
        v.push_back(group[i]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (auto gid : v)
    {
        bfs(gid);
    }
    int answer = 0x7f7f7f7f;
    for (int i = 1; i <= k; i++)
    {
        answer = std::min(answer, score[i]);
    }
    printf("%d\n", answer);
    return 0;
}