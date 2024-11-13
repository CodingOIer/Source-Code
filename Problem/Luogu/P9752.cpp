#include <cstdio>
#include <tuple>
constexpr int MaxN = 1e1 + 5;
int n, m;
std::tuple<int, int, int, int, int> p[MaxN];
inline bool check(int a, int b, int c, int d, int e, int aa, int bb, int cc, int dd, int ee)
{
    int pa, pb, pc, pd, pe;
    pa = a - aa;
    pb = b - bb;
    pc = c - cc;
    pd = d - dd;
    pe = e - ee;
    return (((pa != 0 && pb == 0 && pc == 0 && pd == 0 && pe == 0) ||
             (pa == 0 && pb != 0 && pc == 0 && pd == 0 && pe == 0) ||
             (pa == 0 && pb == 0 && pc != 0 && pd == 0 && pe == 0) ||
             (pa == 0 && pb == 0 && pc == 0 && pd != 0 && pe == 0) ||
             (pa == 0 && pb == 0 && pc == 0 && pd == 0 && pe != 0)) ||
            (pa == pb && pc == 0 && pd == 0 && pe == 0) || (pb == pc && pa == 0 && pd == 0 && pe == 0) ||
            (pc == pd && pa == 0 && pb == 0 && pe == 0) || (pd == pe && pa == 0 && pb == 0 && pc == 0));
}
bool check(int a, int b, int c, int d, int e)
{
    for (int i = 1; i <= n; i++)
    {
        int aa, bb, cc, dd, ee;
        std::tie(aa, bb, cc, dd, ee) = p[i];
        if (!check(a, b, c, d, e, aa, bb, cc, dd, ee))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    m = 5;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        p[i] = {a, b, c, d, e};
    }
    int answer = 0;
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    for (int e = 0; e <= 9; e++)
                    {
                        if (!check(a, b, c, d, e))
                        {
                            printf("%d %d %d %d %d\n", a, b, c, d, e);
                        }
                        answer += check(a, b, c, d, e) ? 1 : 0;
                    }
                }
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}