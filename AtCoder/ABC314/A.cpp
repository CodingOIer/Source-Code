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
int n;
char s[] = {"3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"};
int main()
{
    scanf("%d", &n);
    s[n + 2] = '\0';
    printf("%s\n", s);
    return 0;
}