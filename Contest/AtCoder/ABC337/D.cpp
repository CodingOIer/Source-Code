#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int h, w, k;
int answer;
int *sum_o[MaxN];
int *sum_x[MaxN];
char *s[MaxN];
int main()
{
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 0; i <= h; i++)
    {
        s[i] = new char[w + 5];
        sum_o[i] = new int[w + 5];
        sum_x[i] = new int[w + 5];
        for (int j = 1; j <= w; j++)
        {
            s[i][j] = 0;
            sum_o[i][j] = 0;
            sum_x[i][j] = 0;
        }
    }
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == 'o')
            {
                sum_o[i][j] = sum_o[i - 1][j] + sum_o[i][j - 1] - sum_o[i - 1][j - 1] + 1;
            }
            else
            {
                sum_o[i][j] = sum_o[i - 1][j] + sum_o[i][j - 1] - sum_o[i - 1][j - 1];
            }
            if (s[i][j] == 'x')
            {
                sum_x[i][j] = sum_x[i - 1][j] + sum_x[i][j - 1] - sum_x[i - 1][j - 1] + 1;
            }
            else
            {
                sum_x[i][j] = sum_x[i - 1][j] + sum_x[i][j - 1] - sum_x[i - 1][j - 1];
            }
        }
    }
    answer = 0x3f3f3f3f;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w - k + 1; j++)
        {
            if (sum_x[i][j + k - 1] - sum_x[i][j - 1] - sum_x[i - 1][j + k - 1] + sum_x[i - 1][j - 1] == 0)
            {
                answer = std::min(answer, k - (sum_o[i][j + k - 1] - sum_o[i][j - 1] - sum_o[i - 1][j + k - 1] +
                                               sum_o[i - 1][j - 1]));
                continue;
            }
        }
    }
    for (int i = 1; i <= h - k + 1; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (sum_x[i + k - 1][j] - sum_x[i - 1][j] - sum_x[i + k - 1][j - 1] + sum_x[i - 1][j - 1] == 0)
            {
                answer = std::min(answer, k - (sum_o[i + k - 1][j] - sum_o[i - 1][j] - sum_o[i + k - 1][j - 1] +
                                               sum_o[i - 1][j - 1]));
                continue;
            }
        }
    }
    printf("%d\n", answer == 0x3f3f3f3f ? -1 : answer);
    return 0;
}