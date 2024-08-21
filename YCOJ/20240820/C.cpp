#include <algorithm>
#include <cstdio>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
class frac
{
  public:
    long long x, y;
    frac operator=(const int &x)
    {
        (*this).x = frac(x).x;
        (*this).y = frac(x).y;
        return (*this);
    }
    frac operator=(const frac &x)
    {
        (*this).x = frac(x).x;
        (*this).y = frac(x).y;
        return (*this);
    }
    friend bool operator<(const frac &x, const frac &y)
    {
        return x.x * y.y < y.x * x.y;
    }
    friend bool operator>(const frac &x, const frac &y)
    {
        return y < x;
    }
    friend bool operator==(const frac &x, const frac &y)
    {
        return !(x < y) && !(x > y);
    }
    friend bool operator!=(const frac &x, const frac &y)
    {
        return !(x == y);
    }
    friend bool operator<=(const frac &x, const frac &y)
    {
        return x < y || x == y;
    }
    friend bool operator>=(const frac &x, const frac &y)
    {
        return x > y || x == y;
    }
    friend frac operator+(const frac &x, const frac &y)
    {
        frac res;
        res.x = x.x * y.y + y.x * x.y;
        res.y = x.y * y.y;
        res.format();
        return res;
    }
    friend frac operator-(const frac &x, const frac &y)
    {
        frac res;
        res.x = x.x * y.y - y.x * x.y;
        res.y = x.y * y.y;
        res.format();
        return res;
    }
    friend frac operator*(const frac &x, const frac &y)
    {
        frac res;
        res.x = x.x * y.x;
        res.y = x.y * y.y;
        res.format();
        return res;
    }
    friend frac operator/(const frac &x, const frac &y)
    {
        frac res;
        res.x = x.x * y.y;
        res.y = x.y * y.x;
        res.format();
        return res;
    }
    frac operator+=(const frac &x)
    {
        (*this) = (*this) + x;
        return *this;
    }
    frac operator-=(const frac &x)
    {
        (*this) = (*this) - x;
        return *this;
    }
    frac operator*=(const frac &x)
    {
        (*this) = (*this) * x;
        return *this;
    }
    frac operator/=(const frac &x)
    {
        (*this) = (*this) / x;
        return *this;
    }
    frac(int a = 0, int b = 1)
    {
        x = a;
        y = b;
        (*this).format();
    }
    frac(int a, frac b)
    {
        (*this) = a / b;
        (*this).format();
    }
    frac(frac a, int b)
    {
        (*this) = a / b;
        (*this).format();
    }
    frac(frac a, frac b)
    {
        (*this) = a / b;
        (*this).format();
    }
    void format()
    {
        if (x == 0)
        {
            x = 0;
            y = 1;
            return;
        }
        long long g = std::gcd(x, y);
        x /= g;
        y /= g;
        if (x < 0 && y < 0)
        {
            x = -x;
            y = -y;
        }
        else if (y < 0)
        {
            x = -x;
            y = -y;
        }
    }
};
class ask
{
  public:
    int p, s;
    long long answer;
};
constexpr int MaxN = 2e3 + 5;
int X, K, n, q;
int a[MaxN];
int b[MaxN];
int c[MaxN];
ask query[MaxN];
std::vector<ask *> vector[MaxN];
std::vector<std::tuple<frac, int>> up[MaxN];
std::vector<std::tuple<frac, int>> down[MaxN];
std::vector<std::tuple<frac, int>> points[MaxN];
std::queue<std::tuple<long long, frac>> waiting[MaxN];
int main()
{
    scanf("%d%d%d%d", &X, &K, &n, &q);
    for (int i = 1; i <= n; i++)
    {
        points[i].push_back({{0, 1}, 0});
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (a[j] >= a[i] && b[j] >= b[i])
            {
                std::get<1>(points[i][0]) += c[j];
            }
            else if (a[j] > a[i] || b[j] > b[i])
            {
                frac ki, kj;
                ki = {b[i] - a[i], X};
                kj = {b[j] - a[j], X};
                if (a[j] > a[i])
                {
                    std::get<1>(points[i][0]) += c[j];
                    points[i].push_back({frac({a[j] - a[i], ki - kj}), -c[j]});
                }
                else if (b[j] > b[i])
                {
                    points[i].push_back({frac({a[i] - a[j], kj - ki}), c[j]});
                }
            }
        }
        std::sort(points[i].begin(), points[i].end());
    }
    std::queue<std::tuple<frac, int>> will;
    for (int i = 1; i <= n; i++)
    {
        for (; !will.empty();)
        {
            will.pop();
        }
        for (auto k : points[i])
        {
            will.push(k);
        }
        long long temp = 0;
        for (int j = 0; j <= X - K; j++)
        {
            for (; !will.empty() && std::get<0>(will.front()) < K + j;)
            {
                frac d;
                int x;
                std::tie(d, x) = will.front();
                temp += x;
                will.pop();
                for (; !will.empty() && std::get<0>(will.front()) <= d;)
                {
                    int x;
                    std::tie(std::ignore, x) = will.front();
                    temp += x;
                    will.pop();
                }
                waiting[i].push({temp, d});
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &query[i].p, &query[i].s);
        vector[query[i].p].push_back(&query[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        std::sort(vector[i].begin(), vector[i].end(), [](ask *x, ask *y) -> bool { return x->s < y->s; });
        std::priority_queue<std::tuple<long long, frac>> queue;
        auto last = waiting[i].front();
        for (auto k : vector[i])
        {
            for (; !waiting[i].empty() && std::get<1>(waiting[i].front()) < k->s + K;)
            {
                last = waiting[i].front();
                queue.push(waiting[i].front());
                waiting[i].pop();
            }
            for (; !queue.empty() && std::get<1>(queue.top()) < k->s;)
            {
            }
        }
    }
    return 0;
}