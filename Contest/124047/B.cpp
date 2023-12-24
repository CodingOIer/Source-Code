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
const int MaxN = 1e6 + 5;
int no;
int cnt;
int n, m;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'N')
        {
            no++;
        }
    }
    if (no > n || s[0] == 'Y')
    {
        printf("No solution\n");
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'N')
        {
            cnt++;
            printf("%d ", cnt);
        }
        else if (s[i] == 'Y')
        {
            printf("1 ");
        }
    }
    printf("\n");
    return 0;
}