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
const int MaxN = 1e5 + 5;
int n;
int cnt;
int p[MaxN];
int max[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    cnt = 1;
    max[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        int l, r;
        int ret, mid;
        l = 1;
        r = cnt;
        ret = -1;
        for (; l <= r;)
        {
            mid = (l + r) >> 1;
            if (max[mid] < p[i])
            {
                r = mid - 1;
                ret = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ret == -1)
        {
            cnt++;
            max[cnt] = p[i];
        }
        else
        {
            max[ret] = p[i];
        }
    }
    printf("%d\n", cnt);
    return 0;
}
