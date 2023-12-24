#include <cstdio>
int n;
void solve(int x)
{
    if (x == 1 || x == 0)
    {
        printf("0");
        return;
    }
    bool first = true;
    for (; x != 0;)
    {
        int tmp = 1;
        int cnt = 0;
        for (; tmp * 2 <= x;)
        {
            tmp *= 2;
            cnt++;
        }
        if (!first)
        {
            printf("+");
        }
        first = false;
        x -= tmp;
        printf("2");
        if (cnt != 1)
        {
            printf("(");
            solve(cnt);
            printf(")");
        }
    }
}
int main()
{
    scanf("%d", &n);
    solve(n);
    printf("\n");
    return 0;
}