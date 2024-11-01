#include <cstdio>
#include <queue>
constexpr int MaxN = 2e5 + 5;
int n, m;
int p[MaxN];
std::priority_queue<int> queue;
inline int aftZero(int x)
{
    int res = 0;
    for (; x % 10 == 0;)
    {
        x /= 10;
        res++;
    }
    return res;
}
inline int length(int x)
{
    int res = 0;
    for (; x != 0;)
    {
        x /= 10;
        res++;
    }
    return res;
}
inline void solve()
{
    scanf("%d%d", &n, &m);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        answer += length(p[i]) - aftZero(p[i]);
        queue.push(aftZero(p[i]));
    }
    bool f = true;
    for (; !queue.empty();)
    {
        if (f)
        {
            queue.pop();
        }
        else
        {
            answer += queue.top();
            queue.pop();
        }
        f ^= true;
    }
    printf("%s\n", answer > m ? "Sasha" : "Anna");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}