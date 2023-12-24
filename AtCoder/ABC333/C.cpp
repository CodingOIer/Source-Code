#include <cstdio>
int n;
long long make(int x)
{
    long long res = 0;
    for (int i = 1; i <= x; i++)
    {
        res = res * 10 + 1;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1;; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                cnt++;
                if (cnt == n)
                {
                    printf("%lld\n", make(i) + make(j) + make(k));
                    return 0;
                }
            }
        }
    }
    return 0;
}