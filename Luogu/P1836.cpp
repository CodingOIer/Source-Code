#include <cstdio>
int n;
long long answer;
long long get_sum(int x)
{
    long long res = 0;
    for (; x != 0;)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}
int main()
{
    scanf("%*d%d", &n);
    long long tmp = 0;
    for (int i = 1; i <= 999999; i++)
    {
        tmp += get_sum(i);
    }
    int now = 0;
    for (int i = 1;; i++)
    {
        now = i * 1000000 - 1;
        if (now > n)
        {
            break;
        }
        answer += tmp + get_sum(i - 1) * 1000000;
    }
    now -= 1000000;
    for (int i = now + 1; i <= n; i++)
    {
        answer += get_sum(i);
    }
    printf("%lld\n", answer);
    return 0;
} // zmmwhxwhj770419