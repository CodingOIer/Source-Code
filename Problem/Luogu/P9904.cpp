#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
class node
{
  public:
    int right, down;
    node()
    {
        right = 0;
        down = 0;
    }
};
int n, m, q;
int f[16][MaxN * MaxN];
char s[MaxN];
node p[MaxN][MaxN];
bool way[][5] = {
    {false, false, false, false, false}, {false, false, false, false, true}, {false, false, false, true, false},
    {false, false, true, false, false},  {false, true, false, false, false}, {false, true, true, false, false},
    {false, true, false, true, false},   {false, true, false, false, false}, {false, false, true, true, false},
    {false, false, true, false, true},   {false, false, false, true, true},  {false, true, true, true, false},
    {false, true, true, false, true},    {false, true, false, true, true},   {false, false, true, true, true},
    {false, true, true, true, true},
};
int way_size[] = {0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4};
inline int getColorId(char c)
{
    int res = 0;
    switch (c)
    {
    case 'P': {
        res = 1;
        break;
    }
    case 'C': {
        res = 2;
        break;
    }
    case 'Z': {
        res = 3;
        break;
    }
    case 'N': {
        res = 4;
        break;
    }
    default: {
        res = 0;
        break;
    }
    }
    return res;
}
inline int getId(int x, int y)
{
    return (x - 1) * m + y;
}
inline void init()
{
    for (int k = 1; k <= 15; k++)
    {
        for (int i = 1; i <= n * m; i++)
        {
            f[k][i] = i;
        }
    }
}
inline int find(int k, int x)
{
    if (f[k][x] != x)
    {
        f[k][x] = find(k, f[k][x]);
    }
    return f[k][x];
}
inline void merge(int k, int x, int y)
{
    if (find(k, x) == find(k, y))
    {
        return;
    }
    f[k][find(k, y)] = find(k, x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m - 1; j++)
        {
            p[i][j].right = getColorId(s[j]);
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            p[i][j].down = getColorId(s[j]);
        }
    }
    init();
    for (int k = 1; k <= 15; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (way[k][p[i][j].right])
                {
                    merge(k, getId(i, j), getId(i, j + 1));
                }
                if (way[k][p[i][j].down])
                {
                    merge(k, getId(i, j), getId(i + 1, j));
                }
            }
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        int res = 0x3f3f3f3f;
        for (int k = 1; k <= 15; k++)
        {
            if (find(k, getId(a, b)) == find(k, getId(x, y)))
            {
                res = std::min(res, way_size[k]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}