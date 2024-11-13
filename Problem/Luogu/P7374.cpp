#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e2 + 5;
class str
{
  public:
    long long x;
    long long cnt;
    char s[MaxN][MaxN];
    long long hs, ms, ss, ts;
    long long he, me, se, te;
    long long all_s, all_e;
};
int n;
long long t;
str p[MaxN];
int main()
{
    for (;;)
    {
        n++;
        scanf("%lld", &p[n].x);
        getchar();
        scanf("%lld:%lld:%lld,%lld --> %lld:%lld:%lld,%lld", &p[n].hs, &p[n].ms, &p[n].ss, &p[n].ts, &p[n].he, &p[n].me,
              &p[n].se, &p[n].te);
        for (;;)
        {
            std::cin.getline(p[n].s[p[n].cnt], MaxN);
            if (p[n].s[p[n].cnt + 1][0] == '\0')
            {
                p[n].cnt++;
                break;
            }
            else if (p[n].s[p[n].cnt + 1][0] == '#')
            {
                goto move;
            }
            p[n].cnt++;
        }
        p[n].all_s = 60 * 60 * 1000 * p[n].hs + 60 * 1000 * p[n].ms + 1000 * p[n].ss + p[n].ts;
        p[n].all_e = 60 * 60 * 1000 * p[n].he + 60 * 1000 * p[n].me + 1000 * p[n].se + p[n].te;
    }
move:;
    scanf("%lld", &t);
    for (int i = 1; i <= n; i++)
    {
        p[n].all_s += t;
        p[n].all_e += t;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", p[i].x);
        printf("%02lld:%02lld:%02lld,%03lld --> %02lld:%02lld:%02lld,%03lld", p[n].all_s / (60 * 60 * 1000),
               (p[n].all_s % (60 * 60 * 1000) / (60 * 1000)), ((p[n].all_s % (60 * 60 * 1000) % (60 * 1000) / 1000)),
               ((p[n].all_s % (60 * 60 * 1000) % (60 * 1000) % 1000)), p[n].all_e / (60 * 60 * 1000),
               (p[n].all_e % (60 * 60 * 1000) / (60 * 1000)), ((p[n].all_e % (60 * 60 * 1000) % (60 * 1000) / 1000)),
               ((p[n].all_e % (60 * 60 * 1000) % (60 * 1000) % 1000)));
        for (int i = 1; i <= p[n].cnt; i++)
        {
            printf("%s\n", p[n].s[i]);
        }
        printf("\n");
    }
    return 0;
}