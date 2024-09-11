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
bool yes;
char p[MaxN];
int main()
{
    scanf("%s", p);
    yes = true;
    for (int i = 0; i < strlen(p); i++)
    {
        switch ((i + 1) % 2)
        {
        case (0): {
            if (!(p[i] == 'L' || p[i] == 'U' || p[i] == 'D'))
            {
                yes = false;
            }
            break;
        }
        case (1): {
        }
            if (!(p[i] == 'R' || p[i] == 'U' || p[i] == 'D'))
            {
                yes = false;
            }
            break;
        }
    }
    printf("%s\n", yes ? "Yes" : "No");
    return 0;
}