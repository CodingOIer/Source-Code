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
int n, k;
int answer;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    getchar();
    scanf("%s", s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            answer++;
        }
    }
    printf("%d\n", std::min(answer + 2 * k, n - 1));
    return 0;
}