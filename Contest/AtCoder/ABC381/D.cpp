#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
bool pre[MaxN];
std::set<int> set;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int l, r;
    l = -1;
    r = -1;
    int answer = 0;
    for (int i = 2; i <= n; i += 2)
    {
        if (p[i] != p[i - 1])
        {
            if (l != -1)
            {
                for (; l <= r;)
                {
                    pre[p[l]] = false;
                    l += 2;
                }
            }
            l = -1;
            r = -1;
            continue;
        }
        if (l == -1)
        {
            l = i;
            r = i;
            pre[p[l]] = true;
        }
        else
        {
            r = i;
            for (; pre[p[r]];)
            {
                pre[p[l]] = false;
                l += 2;
            }
            pre[p[r]] = true;
        }
        answer = std::max(answer, r - l + 2);
    }
    for (; l <= r;)
    {
        pre[p[l]] = false;
        l += 2;
    }
    l = -1;
    r = -1;
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i] != p[i - 1])
        {
            if (l != -1)
            {
                for (; l <= r;)
                {
                    pre[p[l]] = false;
                    l += 2;
                }
            }
            l = -1;
            r = -1;
            continue;
        }
        if (l == -1)
        {
            l = i;
            r = i;
            pre[p[l]] = true;
        }
        else
        {
            r = i;
            for (; pre[p[r]];)
            {
                pre[p[l]] = false;
                l += 2;
            }
            pre[p[r]] = true;
        }
        answer = std::max(answer, r - l + 2);
    }
    printf("%d\n", answer);
    return 0;
}
