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
const double eps = 1e-9;
int n;
double l, r;
double p[15];
double fun(double x)
{
    double res;
    res = 0;
    for (int i = n; i >= 0; i--)
    {
        res = res * x + p[i];
    }
    return res;
}
int main()
{
    scanf("%d%lf%lf", &n, &l, &r);
    for (int i = n; i >= 0; i--)
    {
        scanf("%lf", &p[i]);
    }
    for (; fabs(l - r) >= eps;)
    {
        double mid;
        mid = (l + r) / 2;
        if (fun(mid + eps) > fun(mid - eps))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.15lf", r);
    return 0;
}