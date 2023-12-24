#include <bits/stdc++.h>
using namespace std;
long long t;
int main()
{
    scanf("%lld", &t);
    for (long long i = 1;; i++)
    {
        if (i * i <= t)
        {
            printf("%lld ", i * i);
        }
        else
        {
            break;
        }
    }
    return 0;
}