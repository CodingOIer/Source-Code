#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, k;
int p[MaxN];
int s[MaxN];
long long answer;
std::map<int, long long> map;
std::vector<int> v;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        if (map[p[i]] == 0)
        {
            cnt++;
        }
        if (s[i] > map[p[i]])
        {
            if (map[p[i]] != 0)
            {
                v.push_back(map[p[i]]);
            }
            map[p[i]] = s[i];
        }
        else
        {
            v.push_back(s[i]);
        }
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < k - cnt; i++)
    {
        answer += v[i];
    }
    printf("%lld\n", answer);
    return 0;
}