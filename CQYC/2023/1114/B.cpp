#include <cstdio>
#include <cstring>
const int MaxN = 15;
const int MOD = 10007;
long long n, m;
struct Matrix
{
    int num[MaxN][MaxN];
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
    friend void operator*=(Matrix &a, const Matrix &b)
    {
        Matrix res;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                for (int k = 1; k <= 10; k++)
                {
                    res.num[i][j] = (res.num[i][j] + a.num[i][k] * b.num[k][j]) % MOD;
                }
            }
        }
        a = res;
    }
};
Matrix base, now;
Matrix ksm(Matrix &a, long long p)
{
    if (p <= 1)
    {
        return a;
    }
    Matrix res = ksm(a, p / 2);
    res *= res;
    if (p % 2 == 1)
    {
        res *= a;
    }
    return res;
}
int main()
{
    freopen("stair.in", "r", stdin);
    freopen("stair.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    base.num[1][1] = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            base.num[1][i] += base.num[1][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        now.num[i][m] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        now.num[i + 1][i] = 1;
    }
    now = ksm(now, n);
    base *= now;
    printf("%d\n", base.num[1][1]);
    return 0;
}
