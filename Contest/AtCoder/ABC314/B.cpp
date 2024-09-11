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
    int n;
    int id;
    bool f[37];
};

int n;
int x;
int w;
int cnt;
int answer;
int out[MaxN];

str tmp[MaxN];
str p[MaxN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp[i].n);
        tmp[i].id = i;
        for (int j = 1; j <= tmp[i].n; j++)
        {
            scanf("%d", &x);
            tmp[i].f[x] = true;
        }
    }
    scanf("%d", &x);
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i].f[x])
        {
            cnt++;
            p[cnt] = tmp[i];
        }
    }
    std::sort(p + 1, p + 1 + cnt, [](str a, str b) { return a.n < b.n; });
    for (int i = 1; i <= cnt; i++)
    {
        if (p[i].n != p[i - 1].n && i != 1)
        {
            break;
        }
        answer++;
    }
    printf("%d\n", answer);
    for (int i = 1; i <= answer; i++)
    {
        out[i] = p[i].id;
    }
    std::sort(out + 1, out + 1 + answer);
    for (int i = 1; i <= answer; i++)
    {
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}