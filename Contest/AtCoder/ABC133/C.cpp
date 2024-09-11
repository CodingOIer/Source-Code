#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f;
long long l, r;
long long answer;
int main()
{
    scanf("%lld%lld", &l, &r);
    answer = inf;
    for (long long i = l; i <= r; i++)
    {
        for (long long j = i + 1; j <= r; j++)
        {
            answer = std::min(answer, (i * j) % 2019);
            if (answer == 0)
            {
                break;
            }
        }
        if (answer == 0)
        {
            break;
        }
    }
    printf("%lld\n", answer);
    return 0;
}