#include <cstdio>
#include <cstring>
long long l, r;
long long left[15];
long long right[15];
void get_sum(long long *res, long long x, bool zero = false)
{
    for (long long i = 0; i < 15; i++)
    {
        res[i] = 0;
    }
    long long cnt = 0;
    for (; x != 0;)
    {
        res[x % 10]++;
        x /= 10;
        cnt++;
    }
    if (zero)
    {
        res[0] += 2 - cnt;
    }
}
void add(long long *s, long long *t, long long val = 1)
{
    for (long long i = 0; i <= 9; i++)
    {
        s[i] += t[i] * val;
    }
}
int main()
{
    scanf("%lld%lld", &l, &r);
    l--;
    long long tmp[15];
    get_sum(tmp, 0);
    long long res[15];
    for (long long i = 0; i <= 99999; i++)
    {
        get_sum(res, i, true);
        add(tmp, res);
    }
    long long now = 0;
    for (long long i = 1;; i++)
    {
        now = i * 100000 - 1;
        if (now > l)
        {
            break;
        }
        add(left, tmp);
        get_sum(res, i - 1);
        add(left, res, 100000);
    }
    now -= 100000;
    for (long long i = now + 1; i <= l; i++)
    {
        get_sum(res, i);
        add(left, res);
    }

    now = 0;
    for (long long i = 1;; i++)
    {
        now = i * 100000 - 1;
        if (now > r)
        {
            break;
        }
        add(right, tmp);
        get_sum(res, i - 1);
        add(right, res, 100000);
    }
    now -= 100000;
    for (long long i = now + 1; i <= r; i++)
    {
        get_sum(res, i);
        add(right, res);
    }
    /* if (l >= 100000)
    {
        left[0] -= 11;
    }
    if (r >= 100000)
    {
        right[0] -= 11;
    } */
    for (long long i = 0; i <= 9; i++)
    {
        printf("%lld ", right[i] - left[i]);
    }
    printf("\n");
    return 0;
}