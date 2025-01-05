// 100 =

#include <cstdio>
constexpr int MaxN = 2e5 + 5;
class Point
{
  public:
    int px, py;
    inline Point()
    {
        px = py = 0;
    }
    inline Point(int x, int y)
    {
        px = x;
        py = y;
    }
    inline void rotateL()
    {
        (*this) = {py, -px};
    }
    inline void rotateR()
    {
        (*this) = {-py, px};
    }
    inline friend Point operator+(const Point &x, const Point &y)
    {
        return {x.px + y.px, x.py + y.py};
    }
    inline friend Point operator-(const Point &x, const Point &y)
    {
        return {x.px - y.px, x.py - y.py};
    }
    inline Point operator+=(const Point &x)
    {
        return (*this) = (*this) + x;
    }
    inline friend bool operator<(const Point &x, const Point &y)
    {
        return (x.px < y.px) || (x.px == y.px && x.py < y.py);
    }
    inline friend bool operator>(const Point &x, const Point &y)
    {
        return y < x;
    }
    inline friend bool operator==(const Point &x, const Point &y)
    {
        return !(x < y) && !(x > y);
    }
    inline friend bool operator!=(const Point &x, const Point &y)
    {
        return !(x == y);
    }
};

int n, q;
char s[MaxN];

long long to[MaxN * 8];
long long lazyTo[MaxN * 8];

int lazyL[MaxN * 8];
int lazyR[MaxN * 8];
Point tree[MaxN * 8];
Point lazyAppend[MaxN * 8];

inline void downstream(int c)
{
    lazyL[c] %= 4;
    if (lazyL[c])
    {
        for (int i = 1; i <= lazyL[c]; i++)
        {
            tree[c * 2].rotateL();
            tree[c * 2 + 1].rotateL();
            lazyL[c * 2]++;
            lazyL[c * 2 + 1]++;
        }
        lazyL[c] = 0;
    }
    lazyR[c] %= 4;
    if (lazyR[c])
    {
        for (int i = 1; i <= lazyR[c]; i++)
        {
            tree[c * 2].rotateR();
            tree[c * 2 + 1].rotateR();
            lazyR[c * 2]++;
            lazyR[c * 2 + 1]++;
        }
        lazyR[c] = 0;
    }
    if (lazyAppend[c] != Point{0, 0})
    {
        tree[c * 2] += lazyAppend[c];
        tree[c * 2 + 1] += lazyAppend[c];
        lazyAppend[c * 2] += lazyAppend[c];
        lazyAppend[c * 2 + 1] += lazyAppend[c];
        lazyAppend[c] = {0, 0};
    }
}
void changeMove(int c, int s, int t, int l, int r, Point val)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c] += val;
        lazyAppend[c] += val;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeMove(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        changeMove(c * 2 + 1, mid + 1, t, l, r, val);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
void changeRotateL(int c, int s, int t, int l, int r)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c].rotateL();
        lazyL[c]++;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeRotateL(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        changeRotateL(c * 2 + 1, mid + 1, t, l, r);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
void changeRotateR(int c, int s, int t, int l, int r)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        tree[c].rotateR();
        lazyR[c]++;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        changeRotateR(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        changeRotateR(c * 2 + 1, mid + 1, t, l, r);
    }
    tree[c] = tree[c * 2] + tree[c * 2 + 1];
}
Point query(int c, int s, int t, int l, int r)
{
    downstream(c);
    if (l <= s && t <= r)
    {
        return tree[c];
    }
    int mid = (s + t) / 2;
    Point res;
    if (l <= mid)
    {
        res += query(c * 2, s, mid, l, r);
    }
    if (r > mid)
    {
        res += query(c * 2 + 1, mid + 1, t, l, r);
    }
    return res;
}
void build(int c, int s, int t)
{
    if (s == t)
    {
        to[c] = 1e6;
        return;
    }
    int mid = (s + t) / 2;
    build(c * 2, s, mid);
    build(c * 2 + 1, mid + 1, t);
}
void downstream(int c, int s, int t)
{
    if (lazyTo[c] != 0)
    {
        int mid = (s + t) / 2;
        to[c * 2] += lazyTo[c] * (mid - s + 1);
        to[c * 2 + 1] += lazyTo[c] * (t - mid);
        lazyTo[c * 2] += lazyTo[c];
        lazyTo[c * 2 + 1] += lazyTo[c];
        lazyTo[c] = 0;
    }
}
void change(int c, int s, int t, int l, int r, long long val)
{
    downstream(c, s, t);
    if (l <= s && t <= r)
    {
        to[c] += (t - s + 1) * val;
        lazyTo[c] += val;
        return;
    }
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(c * 2, s, mid, l, r, val);
    }
    if (r > mid)
    {
        change(c * 2 + 1, mid + 1, t, l, r, val);
    }
    to[c] = to[c * 2] + to[c * 2 + 1];
}
long long query(int c, int s, int t, int w)
{
    downstream(c, s, t);
    if (s == t)
    {
        return to[c];
    }
    int mid = (s + t) / 2;
    if (w <= mid)
    {
        return query(c * 2, s, mid, w);
    }
    else
    {
        return query(c * 2 + 1, mid + 1, t, w);
    }
}
Point get(Point x, int w)
{
    int r = (query(1, 1, n, w) % 4 + 4) % 4;
    for (int i = 1; i <= r; i++)
    {
        x.rotateR();
    }
    return x;
}
void clear(int x)
{
    if (s[x] == 'W')
    {
        changeMove(1, 1, n, x, x, get({0, -1}, x));
    }
    else if (s[x] == 'S')
    {
        changeMove(1, 1, n, x, x, get({0, 1}, x));
    }
    else if (s[x] == 'A')
    {
        changeRotateR(1, 1, n, x, n);
        change(1, 1, n, x, n, 1);
    }
    else if (s[x] == 'D')
    {
        changeRotateL(1, 1, n, x, n);
        change(1, 1, n, x, n, -1);
    }
    s[x] = '\0';
}
void add(int x, char op)
{
    if (op == 'W')
    {
        changeMove(1, 1, n, x, x, get({0, 1}, x));
    }
    else if (op == 'S')
    {
        changeMove(1, 1, n, x, x, get({0, -1}, x));
    }
    else if (op == 'A')
    {
        changeRotateL(1, 1, n, x, n);
        change(1, 1, n, x, n, -1);
    }
    else if (op == 'D')
    {
        changeRotateR(1, 1, n, x, n);
        change(1, 1, n, x, n, 1);
    }
    s[x] = op;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        add(i, s[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            scanf(" ");
            char ch;
            scanf("%c", &ch);
            clear(x);
            add(x, ch);
        }
        else if (op == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            auto res = query(1, 1, n, l, r);
            int k = l == 1 ? 0 : (query(1, 1, n, l - 1) % 4 + 4) % 4;
            for (int i = 1; i <= k; i++)
            {
                res.rotateL();
            }
            printf("%d %d\n", res.py, res.px);
        }
    }
    return 0;
}