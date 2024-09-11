#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long answer;
int main()
{
    scanf("%lld%lld", &x, &y);
    for (;;)
    {
        if (x > y)
        {
            break;
        }
        answer++;
        x *= 2;
    }
    printf("%lld\n", answer);
    return 0;
}