#include <cstdio>
const int MaxN = 1e2 + 5;
int answer;
int n, h, x;
int p[MaxN];
int main()
{
    scanf("%d%d%d", &n, &h, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] + h < x)
        {
            continue;
        }
        if (p[i] < p[answer] || answer == 0)
        {
            answer = i;
        }
    }
    printf("%d\n", answer);
    return 0;
}