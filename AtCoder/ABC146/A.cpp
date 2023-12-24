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
char s[MaxN];
std::map<std::string, int> map;
int main()
{
    map["SAT"] = 1;
    map["FRI"] = 2;
    map["THU"] = 3;
    map["WED"] = 4;
    map["TUE"] = 5;
    map["MON"] = 6;
    map["SUN"] = 7;
    scanf("%s", s);
    printf("%d\n", map[std::string(s)]);
    return 0;
}