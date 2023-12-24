#include <algorithm>
#include <cmath>
#include <cstdio>
constexpr int MaxN = 1e1 + 5;
class line
{
  public:
    int p[MaxN];
};
class row
{
  public:
    int p[MaxN];
};
int h, w;
int answer;
int temp[MaxN];
int want[MaxN][MaxN];
int link_row[MaxN];
int link_line[MaxN];
row q[MaxN];
line p[MaxN];
int calc(int p[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        temp[i] = p[i];
    }
    int res = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                std::swap(temp[j], temp[j + 1]);
                res++;
            }
        }
    }
    return res;
}
void check()
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (q[link_row[j]].p[i] != want[i][j])
            {
                return;
            }
        }
    }
    int need = calc(link_line, h) + calc(link_row, w);
    if (need < answer || answer == -1)
    {
        answer = need;
    }
}
void solve()
{
    for (int i = 1; i <= w; i++)
    {
        link_row[i] = i;
    }
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            q[i].p[j] = p[link_line[j]].p[i];
        }
    }
    do
    {
        check();
    } while (std::next_permutation(link_row + 1, link_row + 1 + w));
}
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            scanf("%d", &p[i].p[j]);
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            scanf("%d", &want[i][j]);
        }
    }
    answer = -1;
    for (int i = 1; i <= h; i++)
    {
        link_line[i] = i;
    }
    do
    {
        solve();
    } while (std::next_permutation(link_line + 1, link_line + 1 + h));
    printf("%d\n", answer);
    return 0;
}