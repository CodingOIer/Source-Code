#include <cstdio>
const int MaxN = 1e1 + 5;
int n;
int p[MaxN];
int state[MaxN];
void check()
{
    int sum = p[1];
    int last;
    for (int i = 2; i <= n; i++)
    {
        switch (state[i])
        {
        case 1: {
            sum += p[i];
            last = p[i];
            break;
        }
        case 2: {
            sum -= p[i];
            last = -p[i];
            break;
        }
        case 3: {
            sum -= last;
            last = last * 10 + p[i] * (last < 0 ? -1 : 1);
            sum += last;
            break;
        }
        }
    }
    if (sum != 0)
    {
        return;
    }
    printf("%d", p[1]);
    for (int i = 2; i <= n; i++)
    {
        printf("%c%d", " +- "[state[i]], p[i]);
    }
    printf("\n");
}
void dfs(int x)
{
    if (x == n + 1)
    {
        check();
    }
    else
    {
        state[x] = 3;
        dfs(x + 1);
        state[x] = 1;
        dfs(x + 1);
        state[x] = 2;
        dfs(x + 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    dfs(2);
    return 0;
}
/*
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7

1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
*/