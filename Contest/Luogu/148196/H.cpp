#include <cstdio>
#include <map>
#include <vector>
const long long MaxN = 1e5 + 5;
const long long MaxK = 5e3 + 5;
long long k;
long long n;
long long best;
long long cnt[MaxK];
long long point[MaxK];
long long answer[MaxN];
std::vector<long long> test[MaxK];
std::map<long long, long long> link;
int main()
{
    scanf("%lld", &k);
    for (long long i = 1; i <= k; i++)
    {
        scanf("%lld", &cnt[i]);
        for (long long j = 1; j <= cnt[i]; j++)
        {
            long long x;
            scanf("%lld", &x);
            test[i].push_back(x);
        }
        scanf("%lld", &point[i]);
    }
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &answer[i]);
    }
    for (long long i = 1; i <= k; i++)
    {
        long long same = answer[test[i][0]];
        bool accepted = true;
        for (long long j = 1; j < test[i].size(); j++)
        {
            if (same != answer[test[i][j]])
            {
                accepted = false;
            }
        }
        if (accepted)
        {
            link[same] += point[i];
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        if (link[answer[i]] > link[best])
        {
            best = answer[i];
        }
    }
    printf("%lld\n", link[best]);
    printf("%lld\n", best);
    return 0;
}