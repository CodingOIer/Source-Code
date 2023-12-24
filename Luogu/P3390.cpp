#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
const long long Mod = 1e9 + 7;
int n;
class block_matrix
{
  public:
    long long p[MaxN][MaxN];
    block_matrix operator*(const block_matrix &y)
    {
        const block_matrix &x = (*this);
        block_matrix res;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    res.p[i][j] += (x.p[i][k] * y.p[k][j]) % Mod;
                    res.p[i][j] %= Mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%lld%c", p[i][j], " \n"[j != n ? 0 : 1]);
            }
        }
    }
    block_matrix(int x)
    {
        for (int i = 1; i <= n; i++)
        {
            p[i][i] = 1;
        }
    }
    block_matrix()
    {
        memset(p, 0, sizeof p);
    }
};
long long k;
block_matrix matrix;
block_matrix ksm(block_matrix x, long long y)
{
    block_matrix res(n);
    if (y >= 1)
    {
        res = x;
    }
    y--;
    for (; y != 0;)
    {
        if (y % 2 == 1)
        {
            res = res * x;
        }
        y /= 2;
        x = x * x;
    }
    return res;
}
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &matrix.p[i][j]);
        }
    }
    block_matrix answer = ksm(matrix, k);
    answer.print();
    return 0;
}