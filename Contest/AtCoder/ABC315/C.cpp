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
const int MaxN = 3e5 + 5;
class str
{
  public:
    int f, p;
};
int n;
str p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].f, &p[i].p);
    }
    std::sort(
        p + 1, p + 1 #include<algorithm>
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
        const int inf = 0x3f3f3f3f; const int MaxN = 3e5 + 5; class str {
          public:
            int f, p;
        };
        int n; str p[MaxN]; int main() {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d", &p[i].f, &p[i].p);
            }
            std::sort(p + 1, p + 1 + n, [](str a, str b) { return a.p < b.p; });
            for (int i = 1; i <= n - 1; i++)
            {
                if (p[i].f == p[n].f)
                {
                    p[i].p /= 2;
                }
            }
            std::sort(p + 1, p + n, [](str a, str b) { return a.p < b.p; });
            printf("%d\n", p[n].p + p[n - 1].p);
            return 0;
        } + n,
                            [](str a, str b) { return a.p < b.p; });
    for (int i = 1; i <= n - 1; i++)
    {
        if (p[i].f == p[n].f)
        {
            p[i].p /= 2;
        }
    }
    std::sort(p + 1, p + n, [](str a, str b) { return a.p < b.p; });
    printf("%d\n", p[n].p + p[n - 1].p);
    return 0;
}