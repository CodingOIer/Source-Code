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
int t;
bool f;
int s[35];
int k[35];
char p[MaxN];
char h[MaxN];
int len_p, len_h;
void solve()
{
    memset(s, 0, sizeof(s));
    getchar();
    scanf("%s", &p);
    getchar();
    scanf("%s", &h);
    len_p = strlen(p);
    len_h = strlen(h);
    for (int i = 0; i < len_p; i++)
    {
        s[p[i] - 'a']++;
    }
    for (int i = 0; i <= len_h - len_p; i++)
    {
        memset(k, 0, sizeof(k));
        for (int j = 0; j < len_p; j++)
        {
            k[h[i + j] - 'a']++;
        }
        f = true;
        for (int i = 0; i < 26; i++)
        {
            if (k[i] != s[i])
            {
                f = false;
            }
        }
        if (f)
        {
            printf("YES\n", i);
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}