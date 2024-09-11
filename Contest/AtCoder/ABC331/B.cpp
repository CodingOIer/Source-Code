#include <algorithm>
#include <cstdio>
int n;
int answer;
int s, m, l;
int main()
{
    scanf("%d", &n);
    scanf("%d%d%d", &s, &m, &l);
    answer = 2e9;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                answer = std::min(answer, 6 * i + 8 * j + 12 * k >= n ? s * i + m * j + l * k : (int)(2e9));
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}