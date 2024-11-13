#include <cstdio>
int n;
long long answer;
int main()
{
    scanf("%d", &n);
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        for (; x % 5 == 0;)
        {
            x /= 5;
            cnt++;
        }
        answer += cnt;
    }
    printf("%lld\n", answer);
    return 0;
}