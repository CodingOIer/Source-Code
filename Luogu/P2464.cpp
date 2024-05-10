#include <cmath>
#include <cstdio>
#include <unordered_map>
constexpr int MaxN = 1e5 + 5;
constexpr int MaxK = 1e3 + 5;
int n, m, k;
int p[MaxN];
std::unordered_map<int, int> map[MaxK];
inline int gb(int x)
{
    return (x - 1) / k + 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    k = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        map[gb(i)][p[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int op = '\0';
        for (; !(op == 'C' || op == 'Q');)
        {
            op = getchar();
        }
        if (op == 'C')
        {
            int x, y;
            scanf("%d%d", &x, &y);
            map[gb(x)][p[x]]--;
            p[x] = y;
            map[gb(x)][p[x]]++;
        }
        else if (op == 'Q')
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            int answer = 0;
            int a, b;
            a = gb(l) + 1;
            b = gb(r) - 1;
            for (; gb(l) != a && l <= r;)
            {
                answer += (p[l] == x ? 1 : 0);
                l++;
            }
            for (; gb(r) != b && r >= l;)
            {
                answer += (p[r] == x ? 1 : 0);
                r--;
            }
            for (int i = a; i <= b; i++)
            {
                answer += map[i][x];
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}