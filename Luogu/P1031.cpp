#include <cstdio>
const int MaxN = 1e2 + 5;
int n;
int sum;
int move;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        sum += p[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (p[i] == sum / n)
        {
            continue;
        }
        int change = p[i] - sum / n;
        p[i + 1] += change;
        move++;
    }
    printf("%d\n", move);
    return 0;
}