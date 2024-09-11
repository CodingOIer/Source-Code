#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long n, d;
int main()
{
    scanf("%lld%lld%lld%lld", &a, &b, &n, &d);
    a--;
    printf("%lld\n", b - a - b / n + a / n - b / d + a / d + b / (n * d / __gcd(n, d)) - a / (n * d / __gcd(n, d)));
    return 0;
}