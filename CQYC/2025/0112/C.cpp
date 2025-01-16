#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n, q;
int id[MaxN];
int begin[MaxN];
int prefix[MaxN];
char s[MaxN];
std::vector<std::tuple<std::string, int>> v;
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        std::string str;
        for (int j = i; j <= n; j++)
        {
            str += s[j];
            v.push_back({str, j});
        }
    }
    std::sort(v.begin(), v.end());
    int cnt = 1;
    prefix[1] = 1;
    for (const auto &[str, x] : v)
    {
        printf("%s\n", str.c_str());
        cnt++;
        begin[cnt - 1] = x;
        prefix[cnt] = prefix[cnt - 1] + str.size();
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        int l, r, res;
        l = 1;
        r = cnt;
        res = -1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (prefix[mid] <= x)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", begin[res] + (x - prefix[res]));
    }
    return 0;
}
