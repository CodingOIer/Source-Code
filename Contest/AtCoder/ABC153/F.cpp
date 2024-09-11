#include <algorithm>
#include <cstdio>
#include <vector>
template <typename T> class Tree
{
    std::vector<T> tree, lazy;
    std::vector<T> *arr;
    int n, root, n4, end;
    void maintain(int cl, int cr, int p)
    {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && lazy[p])
        {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] += lazy[p] * (cr - cm);
            lazy[p] = 0;
        }
    }
    T range_sum(int l, int r, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
            return tree[p];
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= m)
            sum += range_sum(l, r, cl, m, p * 2);
        if (r > m)
            sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }
    void range_add(int l, int r, T val, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
        {
            lazy[p] += val;
            tree[p] += (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m)
            range_add(l, r, val, cl, m, p * 2);
        if (r > m)
            range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
    void build(int s, int t, int p)
    {
        if (s == t)
        {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

  public:
    explicit Tree<T>(std::vector<T> v)
    {
        n = v.size();
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<T>(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }
    void show(int p, int depth = 0)
    {
        if (p > n4 || tree[p] == 0)
            return;
        show(p * 2, depth + 1);
        for (int i = 0; i < depth; ++i)
            putchar('\t');
        printf("%lld:%lld\n", tree[p], lazy[p]);
        show(p * 2 + 1, depth + 1);
    }
    T sum(int l, int r)
    {
        return range_sum(l, r, 0, end, root);
    }
    void add(int l, int r, int val)
    {
        range_add(l, r, val, 0, end, root);
    }
};
const int MaxN = 2e5 + 5;
long long x;
long long need;
long long n, d, a;
long long answer;
std::pair<long long, long long> p[MaxN];
std::vector<long long> v;
int main()
{
    scanf("%lld%lld%lld", &n, &d, &a);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &p[i].first, &p[i].second);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        v.push_back(p[i].second);
    }
    Tree<long long> t(v);
    for (int i = 1; i <= n; i++)
    {
        if (t.sum(i - 1, i - 1) <= 0)
        {
            continue;
        }
        x = t.sum(i - 1, i - 1);
        need = x / a + (x % a ? 1 : 0);
        int l, r;
        int result;
        l = 1;
        r = n;
        for (; l <= r;)
        {
            int mid;
            mid = (l + r) / 2;
            if (p[mid].first <= p[i].first + 2 * d)
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        t.add(i - 1, result - 1, -need * a);
        answer += need;
    }
    printf("%lld\n", answer);
    return 0;
}