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
const int MaxN = 1e8 + 5;
int n;
int q;
int k;
int cnt;
bool f[MaxN];
int ans[MaxN];
void init(int max)
{
    f[1] = true;
    for (int i = 2; i <= max; i++)
    {
        if (!f[i])
        {
            cnt++;
            ans[cnt] = i;
            for (int j = 2; i * j <= max; j++)
            {
                f[i * j] = true;
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    init(n);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
    return 0;
}