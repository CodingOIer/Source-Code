#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
class Sol
{
  public:
    int l, r;
    int begin;
    int value;
    Sol(const int &, const int &, const int &);
    friend bool operator<(const Sol &, const Sol &);
};
constexpr int MaxN = 5e5 + 5;
int n, k, l, r;
int p[MaxN];
int lg[MaxN];
int st[21][MaxN];
int prefixSum[MaxN];
std::priority_queue<Sol> queue;
int whichMax(int x, int y)
{
    return prefixSum[x] > prefixSum[y] ? x : y;
}
int maxWhere(int l, int r)
{
    if (l > r)
    {
        std::swap(l, r);
    }
    int j = lg[r - l + 1];
    return whichMax(st[j][l], st[j][r - (1 << j) + 1]);
}
Sol::Sol(const int &_begin, const int &_l, const int &_r)
{
    l = _l;
    r = _r;
    begin = _begin;
    value = prefixSum[maxWhere(l, r)] - prefixSum[begin - 1];
}
bool operator<(const Sol &x, const Sol &y)
{
    return x.value < y.value;
}
int main()
{
    scanf("%d%d%d%d", &n, &k, &l, &r);
    lg[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        st[0][i] = i;
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = whichMax(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i + l - 1 <= n)
        {
            queue.push(Sol(i, i + l - 1, std::min(i + r - 1, n)));
        }
    }
    long long answer = 0;
    for (int i = 1; i <= k; i++)
    {
        Sol x = queue.top();
        queue.pop();
        answer += x.value;
        int w = maxWhere(x.l, x.r);
        if (x.l < w)
        {
            queue.push({x.begin, x.l, w - 1});
        }
        if (w < x.r)
        {
            queue.push({x.begin, w + 1, x.r});
        }
    }
    printf("%lld\n", answer);
    return 0;
}
