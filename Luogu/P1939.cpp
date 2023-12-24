#include <cstdio>
#include <cstring>
const int MaxN = 5;
const long long Mod = 1e9 + 7;
int n = 3;
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
int t;
int x;
block_matrix matrix;
block_matrix ksm(block_matrix x, long long y)
{
    block_matrix res;
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
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &x);
        matrix.p[1][1] = 1;
        matrix.p[1][2] = 0;
        matrix.p[1][3] = 1;
        matrix.p[2][1] = 1;
        matrix.p[2][2] = 0;
        matrix.p[2][3] = 0;
        matrix.p[3][1] = 0;
        matrix.p[3][2] = 1;
        matrix.p[3][3] = 0;
        block_matrix answer = ksm(matrix, x);
        printf("%lld\n", answer.p[2][1]);
    }
    return 0;
}