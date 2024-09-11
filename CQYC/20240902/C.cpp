#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
#include <vector>
constexpr int MaxN = 5e5 + 5;
int n, m;
int nn, mm;
int a[MaxN];
int b[MaxN];
int aa[MaxN];
int bb[MaxN];
int sua[MaxN];
int sub[MaxN];
char p[MaxN];
std::vector<std::tuple<int, int>> calc()
{
    std::vector<std::tuple<int, int>> way;
    int sa, sb;
    sa = 1;
    sb = 1;
    int a, b;
    a = 1;
    b = 1;
    for (; a <= nn - 1 && b <= mm - 1;)
    {
        for (; aa[a] == aa[a + 1];)
        {
            a++;
            sa++;
        }
        for (; bb[b] == bb[b + 1];)
        {
            b++;
            sb++;
        }
        if (aa[a + 1] != 0 || bb[b + 1] != 0)
        {
            way.push_back({sa, sb});
            std::swap(sa, sb);
            sa++;
            sb++;
            a++;
            b++;
        }
    }
    if (a > nn)
    {
        a--;
        sa--;
    }
    if (b > mm)
    {
        b--;
        sb--;
    }
    for (; a <= nn - 1;)
    {
        for (; aa[a] == aa[a + 1];)
        {
            a++;
            sa++;
        }
        if (aa[a + 1] != 0)
        {
            way.push_back({sa, sb});
            std::swap(sa, sb);
            a++;
            sa++;
        }
    }
    for (; b <= mm - 1;)
    {
        for (; bb[b] == bb[b + 1];)
        {
            b++;
            sb++;
        }
        if (bb[b + 1] != 0)
        {
            way.push_back({sa, sb});
            std::swap(sa, sb);
            b++;
            sb++;
        }
    }
    return way;
}
inline int generate(int x, int y)
{
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    nn = n + y - x;
    mm = m + x - y;
    for (int i = 1; i <= y; i++)
    {
        aa[i] = b[i];
    }
    for (int i = y + 1; i <= nn; i++)
    {
        aa[i] = a[i - y + x];
    }
    for (int i = 1; i <= x; i++)
    {
        bb[i] = a[i];
    }
    for (int i = x + 1; i <= mm; i++)
    {
        bb[i] = b[i - x + y];
    }
    return x == 0 && y == 0 ? 0 : 1;
}
int main()
{
    scanf("%s", p + 1);
    n = strlen(p + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (p[i] == 'a' ? 1 : 2);
        if (i >= 2)
        {
            sua[i - 1] = sua[i - 2];
            if (i >= 2 && a[i] != a[i - 1])
            {
                sua[i - 1]++;
            }
        }
    }
    scanf("%s", p + 1);
    m = strlen(p + 1);
    for (int i = 1; i <= m; i++)
    {
        b[i] = (p[i] == 'a' ? 1 : 2);
        sub[i - 1] = sub[i - 2];
        if (i >= 2)
        {
            if (i >= 2 && b[i] != b[i - 1])
            {
                sub[i - 1]++;
            }
        }
    }
    std::tuple<int, int> pre;
    int best = 0x7f7f7f7f;
    std::vector<std::tuple<int, int>> answer;
    if (sua[n - 1] < sub[m - 1])
    {
        for (int i = 0; i <= m; i++)
        {
            if (i <= m - 1)
            {
                int cna, cnb;
                cna = sua[n - 1] + sub[i] - (sub[i] % 2 == 0 ? 1 : 0);
                cnb = sub[m - 1] - sub[i] - (b[i] == b[i + 1] ? 1 : 0);
                if (abs(cna - cnb) <= 2 && (i == 0 ? a[1] != b[1] : b[1] != b[i + 1]))
                {
                    int cnt = 0;
                    for (int j = 1; j <= n; j++)
                    {
                        if (a[j] != b[i + 1])
                        {
                            break;
                        }
                        cnt++;
                    }
                    int r = generate(cnt, i);
                    auto sol = calc();
                    if (sol.size() + r < best)
                    {
                        best = sol.size() + r;
                        answer = sol;
                        if (r == 1)
                        {
                            pre = {cnt, i};
                        }
                        else
                        {
                            pre = {-1, -1};
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            if (i <= n - 1)
            {
                int cna, cnb;
                cna = sua[n - 1] - sua[i] - (a[i] == a[i + 1] ? 1 : 0);
                cnb = sub[m - 1] + sua[i] - (sua[i] % 2 == 0 ? 1 : 0);
                if (abs(cna - cnb) <= 2 && (i == 0 ? a[1] != b[1] : a[1] != a[i + 1]))
                {
                    int cnt = 0;
                    for (int j = 1; j <= m; j++)
                    {
                        if (b[j] != a[i + 1])
                        {
                            break;
                        }
                        cnt++;
                    }
                    int r = generate(i, cnt);
                    auto sol = calc();
                    if (sol.size() + r < best)
                    {
                        best = sol.size() + r;
                        answer = sol;
                        if (r == 1)
                        {
                            pre = {i, cnt};
                        }
                        else
                        {
                            pre = {-1, -1};
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", int(answer.size()) + (std::get<0>(pre) == -1 ? 0 : 1));
    if (std::get<0>(pre) != -1)
    {
        auto [x, y] = pre;
        printf("%d %d\n", x, y);
    }
    for (auto [x, y] : answer)
    {
        printf("%d %d\n", x, y);
    }
    return 0;
}