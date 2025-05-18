#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int xa, ya;
int xb, yb;
int answer;
int suffix[MaxN];
std::vector<std::tuple<double, double>> v;
double dis(int sx, int sy, int x, int y)
{
    return sqrt(abs(sx - x) * abs(sx - x) + abs(sy - y) * abs(sy - y));
}
int main()
{
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back({dis(xa, ya, x, y), dis(xb, yb, x, y)});
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    int cnt = n;
    for (const auto &[x, y] : v)
    {
        suffix[cnt] = std::max(suffix[cnt + 1], int(y * y + 1e-7));
        cnt--;
    }
    std::reverse(v.begin(), v.end());
    cnt = 1;
    answer = suffix[1];
    for (const auto &[x, y] : v)
    {
        answer = std::min(answer, int(x * x + 1e-7) + suffix[cnt + 1]);
        cnt++;
    }
    printf("%d\n", answer);
    return 0;
}