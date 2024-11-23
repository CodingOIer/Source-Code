#include <algorithm>
#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, q;
int one[MaxN];
int two[MaxN];
char s[MaxN];
std::vector<int> v;
int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '/')
        {
            v.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        one[i] = one[i - 1];
        if (s[i] == '1')
        {
            one[i]++;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        two[i] = two[i + 1];
        if (s[i] == '2')
        {
            two[i]++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int cl, cr;
        cl = l;
        cr = r;
        auto itl = std::lower_bound(v.begin(), v.end(), l);
        auto itr = std::upper_bound(v.begin(), v.end(), r);
        itr--;
        l = itl - v.begin();
        r = itr - v.begin();
        if (l > r)
        {
            printf("0\n");
            continue;
        }
        int best = -1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            best = std::max(std::min(one[v[mid] - 1] - one[cl - 1], two[v[mid] + 1] - two[cr + 1]), best);
            if (one[v[mid] - 1] - one[cl - 1] > two[v[mid] + 1] - two[cr + 1])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", best * 2 + 1);
    }
    return 0;
}
