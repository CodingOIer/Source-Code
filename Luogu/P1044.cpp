#include <cstdio>
#include <random>
#include <unordered_map>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 1e2 + 5;
int n;
int answer;
std::unordered_map<unsigned int>
int state[MaxN];
void dfs(int x)
{
    if (x == n + 1)
    {
        check();
    }
    else
    {
        state[x] = 1;
        dfs(x + 1);
        state[x] = 2;
        dfs(x + 1);
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}