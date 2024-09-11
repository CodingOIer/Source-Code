#include <cstdio>
const int MaxN = 2e5 + 5;
int x;
int n, m;
int winner;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    winner = 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        p[x]++;
        if (p[x] > p[winner] || (p[x] == p[winner] && x < winner))
        {
            winner = x;
        }
        printf("%d\n", winner);
    }
    return 0;
}