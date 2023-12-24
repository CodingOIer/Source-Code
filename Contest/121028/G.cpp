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
const int Len = 1e2 + 5;
int cnt;
int n, m, l;
char t[Len];
char s[MaxN][Len];
char join[MaxN][Len];
std::string answer[2 * MaxN];
std::map<std::string, bool> map;
int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", t);
        map[std::string(t)] = true;
    }
    for (int i = 1; i <= l; i++)
    {
        scanf("%s", join[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!map[std::string(s[i])])
        {
            cnt++;
            answer[cnt] = s[i];
        }
    }
    for (int i = 1; i <= l; i++)
    {
        cnt++;
        answer[cnt] = join[i];
    }
    std::sort(answer + 1, answer + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%s\n", answer[i].c_str());
    }
    return 0;
}