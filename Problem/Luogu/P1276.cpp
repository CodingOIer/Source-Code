#include <cstdio>
constexpr int MaxL = 1e4 + 5;
int r, n;
int sta[MaxL];
int main()
{
    scanf("%d%d", &r, &n);
    int removeAgain = 0;
    for (int i = 0; i <= r; i++)
    {
        sta[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 0)
        {
            for (int j = l; j <= r; j++)
            {
                if (sta[j] == 1)
                {
                    sta[j] = 0;
                }
                if (sta[j] == 2)
                {
                    removeAgain++;
                    sta[j] = 0;
                }
            }
        }
        if (op == 1)
        {
            for (int j = l; j <= r; j++)
            {
                if (sta[j] == 0)
                {
                    sta[j] = 2;
                }
            }
        }
    }
    int stillLive = 0;
    for (int i = 0; i <= r; i++)
    {
        stillLive += sta[i] == 2 ? 1 : 0;
    }
    printf("%d\n", stillLive);
    printf("%d\n", removeAgain);
    return 0;
}
