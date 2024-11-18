#include <algorithm>
#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int peo = 0;
    for (int i = 1; i <= n; i++)
    {
        char op;
        scanf(" ");
        scanf("%c", &op);
        if (op == 'P')
        {
            int x;
            scanf("%d", &x);
            peo += x;
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%s\n", peo < x ? "Yes" : "No");
            peo = std::max(0, peo - x);
        }
    }
    return 0;
}
