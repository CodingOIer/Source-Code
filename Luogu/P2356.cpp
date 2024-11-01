#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n;
int p[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    int answer = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i][j] != 0)
            {
                continue;
            }
            int temp = 0;
            for (int k = 1; k <= n; k++)
            {
                temp += p[i][k] + p[k][j];
            }
            answer = std::max(answer, temp);
        }
    }
    if (answer == -1)
    {
        printf("Bad Game!\n");
    }
    else
    {
        printf("%d\n", answer);
    }
    return 0;
}