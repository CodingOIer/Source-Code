#include <cstdio>
#include <map>
#include <stack>
#include <utility>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int pl;
int pr;
int max;
int n, k;
int dp[MaxN];
bool vis[MaxN];
std::stack<int> stack;
std::vector<int> lk[MaxN];
std::map<std::pair<int, int>, int> map;
std::pair<int, int> get_length(int u, int f)
{
    dp[u] = 0;
    int fi, se, pfi, pse;
    fi = 0;
    se = 0;
    pfi = u;
    pse = u;
    for (auto v : lk[u])
    {
        if (v == f)
        {
            continue;
        }
        auto r = get_length(v, u);
        r.first += map[{u, v}];
        if (r.first > fi)
        {
            se = fi;
            pse = pfi;
            fi = r.first;
            pfi = r.second;
        }
        else if (r.first > se)
        {
            se = r.first;
            pse = r.second;
        }
    }
    if (fi + se > max)
    {
        pl = pfi;
        pr = pse;
        max = fi + se;
    }
    return {fi, pfi};
}
bool flag(int u, int f)
{
    if (u == pr)
    {
        int l = u;
        for (; l != pl;)
        {
            map[{l, stack.top()}] = -1;
            map[{stack.top(), l}] = -1;
            l = stack.top();
            stack.pop();
        }
        return true;
    }
    vis[u] = true;
    stack.push(u);
    for (auto v : lk[u])
    {
        if (v == f)
        {
            continue;
        }
        if (flag(v, u))
        {
            return true;
        }
    }
    stack.pop();
    vis[u] = false;
    return false;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        lk[u].push_back(v);
        lk[v].push_back(u);
        map[{u, v}] = 1;
        map[{v, u}] = 1;
    }
    int answer = 2 * (n - 1);
    if (k == 1)
    {
        get_length(1, 0);
        answer -= max - 1;
        printf("%d\n", answer);
    }
    else if (k == 2)
    {
        get_length(1, 0);
        answer -= max - 1;
        flag(pl, 0);
        max = 0;
        get_length(1, 0);
        answer -= max - 1;
        printf("%d\n", answer);
    }
    return 0;
}