#include <cstdio>
#include <map>
constexpr int MaxN = 2e5 + 5;
int n, q;
long long copy;
long long p[MaxN];
std::map<int, bool> done;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        done[i] = true;
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
            done.clear();
            copy = x;
        }
        else if (op == 2)
        {
            int w, x;
            scanf("%d%d", &w, &x);
            if (!done[w])
            {
                p[w] = copy;
                done[w] = true;
            }
            p[w] += x;
        }
        else if (op == 3)
        {
            int x;
            scanf("%d", &x);
            if (!done[x])
            {
                p[x] = copy;
                done[x] = true;
            }
            printf("%lld\n", p[x]);
        }
    }
    return 0;
}