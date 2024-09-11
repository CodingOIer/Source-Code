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
const int MaxN = 2e5 + 5;

int n, m;
int p[MaxN];
int cnt[MaxN];

char s[MaxN];

std::string t[MaxN];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        t[p[i]] += s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[p[i]] == 0)
        {
            printf("%c", t[p[i]][t[p[i]].size() - 1]);
        }
        else
        {
            printf("%c", t[p[i]][cnt[p[i]] - 1]);
        }
        cnt[p[i]]++;
    }
    printf("\n");
    return 0;
}