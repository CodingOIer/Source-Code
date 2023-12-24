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
ll answer;
int from_len;
int want_len;
char from[MaxN];
char want[MaxN];
int main()
{
    scanf("%s", from);
    getchar();
    scanf("%s", want);
    getchar();
    from_len = strlen(from);
    want_len = strlen(want);
    for (register int i = 0, j = 0; i < want_len && answer <= 1e8; answer++)
    {
        if (from[j] == want[i])
        {
            i++;
        }
        j++;
        if (j == from_len)
        {
            j = 0;
        }
    }
    printf("%lld\n", answer);
    return 0;
}