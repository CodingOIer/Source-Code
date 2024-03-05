#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
constexpr int MaxK = 2e5 + 5;
class node
{
  public:
    int cnt;
    int answer;
    int x, y, z;
    friend bool operator==(const node &__x, const node &__y)
    {
        return __x.x == __y.x && __x.y == __y.y && __x.z == __y.z;
    }
    friend bool operator!=(const node &__x, const node &__y)
    {
        return !(__x == __y);
    }
};
int n, m, k;
int tree[MaxK];
int answer[MaxN];
node t[MaxN];
node p[MaxN];
bool cmpX(const node &__x, const node &__y)
{
    return __x.x < __y.x || ((__x.x == __y.x && __x.y < __y.y) || (__x.y == __y.y && __x.z < __y.z));
}
bool cmpY(const node &__x, const node &__y)
{
    return __x.y < __y.y || (__x.y == __y.y && __x.z < __y.z);
}
inline int lowerBit(int x)
{
    return x & -x;
}
inline void change(int x, int val)
{
    for (; x <= k; x += lowerBit(x))
    {
        tree[x] += val;
    }
}
inline int query(int x)
{
    int res = 0;
    for (; x > 0; x -= lowerBit(x))
    {
        res += tree[x];
    }
    return res;
}
void solve(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    std::sort(p + l, p + mid + 1, cmpY);
    std::sort(p + mid + 1, p + r + 1, cmpY);
    int k = l;
    for (int i = mid + 1; i <= r; i++)
    {
        for (; p[k].y <= p[i].y && k <= mid;)
        {
            change(p[k].z, p[k].cnt);
            k++;
        }
        p[i].answer += query(p[i].z);
    }
    for (int i = l; i < k; i++)
    {
        change(p[i].z, -p[i].cnt);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &t[i].x, &t[i].y, &t[i].z);
    }
    std::sort(t + 1, t + 1 + n, cmpX);
    int same = 0;
    for (int i = 1; i <= n; i++)
    {
        same++;
        if (t[i] != t[i + 1])
        {
            m++;
            p[m] = t[i];
            p[m].cnt = same;
            same = 0;
        }
    }
    solve(1, m);
    for (int i = 1; i <= m; i++)
    {
        answer[p[i].answer + p[i].cnt - 1] += p[i].cnt;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}