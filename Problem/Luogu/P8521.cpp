#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
constexpr int MaxN = 1e5 + 5;
int a[MaxN];
int b[MaxN];
int s[5][5];
int sa[MaxN][5];
int sb[MaxN][5];
int sc[MaxN][5][5];
void init(std::string _a, std::string _b)
{
    int l = _a.size();
    _a = " " + _a;
    _b = " " + _b;
    for (int i = 1; i <= l; i++)
    {
        a[i] = _a[i] == 'A' ? 1 : _a[i] == 'T' ? 2 : 3;
        b[i] = _b[i] == 'A' ? 1 : _b[i] == 'T' ? 2 : 3;
        for (int x = 1; x <= 3; x++)
        {
            sa[i][x] = sa[i - 1][x];
            sb[i][x] = sb[i - 1][x];
            for (int y = 1; y <= 3; y++)
            {
                sc[i][x][y] = sc[i - 1][x][y];
            }
        }
        sa[i][a[i]]++;
        sb[i][b[i]]++;
        if (a[i] != b[i])
        {
            sc[i][a[i]][b[i]]++;
        }
    }
}
int get_distance(int l, int r)
{
    l++;
    r++;
    for (int x = 1; x <= 3; x++)
    {
        if (sa[r][x] - sa[l - 1][x] != sb[r][x] - sb[l - 1][x])
        {
            return -1;
        }
    }
    for (int x = 1; x <= 3; x++)
    {
        for (int y = 1; y <= 3; y++)
        {
            s[x][y] = sc[r][x][y] - sc[l - 1][x][y];
        }
    }
    int res = 0;
    for (int x = 1; x <= 3; x++)
    {
        for (int y = 1; y <= x - 1; y++)
        {
            int l = std::min(s[x][y], s[y][x]);
            res += l;
            s[x][y] -= l;
            s[y][x] -= l;
        }
    }
    int k = 0;
    for (int x = 1; x <= 3; x++)
    {
        for (int y = 1; y <= 3; y++)
        {
            k += s[x][y];
        }
    }
    return res + k / 3 * 2;
}
#ifndef ONLINE_JUDGE
int main()
{
    int n, k;
    std::string a, b;
    scanf("%d%d", &n, &k);
    std::cin >> a;
    std::cin >> b;
    init(a, b);
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", get_distance(l, r));
    }
    return 0;
}
#endif