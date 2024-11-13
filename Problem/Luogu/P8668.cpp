#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long cycle;
long long answer;
int main()
{
    scanf("%lld%lld", &x, &y);
    cycle = max(x, y);
    answer += (8 + cycle * 8) * cycle / 2;
    if (x < y)
    {
    }
    return 0;
}