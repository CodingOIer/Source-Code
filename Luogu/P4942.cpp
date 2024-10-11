#include <cstdio>
int q;
int main()
{
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        l %= 9;
        r %= 9;
        r += 9;
        int s = 0;
        for (int i = l; i <= r; i++)
        {
            s += i;
        }
        printf("%d\n", s % 9);
    }
    return 0;
}