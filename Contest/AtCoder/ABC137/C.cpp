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
const int MaxM = 1e1 + 5;
int n;
ll answer;
std::string s;
char input[MaxN];
std::unordered_map<std::string, ll> have;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", input);
        s = (input);
        std::sort(s.begin(), s.end());
        if (have[s])
        {
            answer += have[s];
        }
        have[s]++;
    }
    printf("%lld\n", answer);
    return 0;
}