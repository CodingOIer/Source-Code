#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define debug printf("Debug\n")
typedef long long ll;
ll answer;
ll a, b, p;
int main()
{
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=", a, b, p);
    answer = 1;
    for (; b != 0;)
    {
        if (b & 1)
        {
            answer = (answer * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    printf("%lld\n", answer);
    return 0;
}