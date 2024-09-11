#include <algorithm>
#include <cstdio>
const int MaxN = 2e6 + 5;
long long answer;
long long l, r, k;
long long p[MaxN];
void init()
{
    p[1] = 1;
    for (int i = 2; i <= 2e6; i++)
    {
        p[i] = (p[i - 1] * i) % k;
    }
}
int main()
{
    scanf("%lld%lld%lld", &l, &r, &k);
    init();
    for (int i = l; i <= r; i++)
    {
        answer = std::max(answer, p[i]);
    }
    printf("%lld\n", answer);
    return 0;
}