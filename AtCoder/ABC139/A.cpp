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
const int MaxN = 5;
int answer;
char s1[MaxN];
char s2[MaxN];
int main()
{
    scanf("%s", s1);
    getchar();
    scanf("%s", s2);
    getchar();
    for (int i = 0; i < 3; i++)
    {
        if (s1[i] == s2[i])
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}