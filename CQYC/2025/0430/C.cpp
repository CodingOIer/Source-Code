#include <algorithm>
#include <cstdio>
#include <tuple>
constexpr int MaxN = 2e1 + 5;
int n;
int p[MaxN];
int lg2[MaxN];
std::tuple<int, int, int, int> st[21][MaxN];
std::tuple<int, int, int, int> stTop(std::tuple<int, int, int, int> x, std::tuple<int, int, int, int> y)
{
    std::tuple<int, int, int, int> res;
    std::get<0>(res) = std::get<0>(x) > std::get<0>(y) ? std::get<1>(x) : std::get<1>(y);
    std::get<2>(res) = std::max(std::get<2>(x), std::get<2>(y));
    std::get<3>(res) = std::max(std::get<3>(x), std::get<3>(y));
    return res;
}
std::tuple<int, int, int, int> query(int l, int r)
{
    int j = lg2[r - l + 1];
    return stTop(st[j][l], st[j][r - (1 << j) + 1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        st[0][i] = {p[i], i, p[i] + i, p[i] + (n - i + 1)};
    }
    for (int j = 1; j <= 19; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = stTop(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    return 0;
}