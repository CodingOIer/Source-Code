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
int n;
int one;
double answer;
int main()
{
    scanf("%d", &n);
    one = n / 2;
    if (n % 2 == 1)
    {
        one++;
    }
    answer = double(one) / double(n);
    printf("%.6f\n", answer);
    return 0;
}