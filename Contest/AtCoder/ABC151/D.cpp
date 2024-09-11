#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 2525 + 5;

int h, w;

int cnt;

int answer;

int id[MaxN][MaxN];

int floyd[MaxN][MaxN];

char map[MaxN][MaxN];

int main()
{
    scanf("%d%d", &h, &w);

    memset(floyd, 0x3f, sizeof(floyd));

    for (int i = 1; i <= 20; i++)
    {
        floyd[i][i] = 0;
    }

    for (int i = 1; i <= h; i++)
    {
        scanf("%s", (map[i] + 1));

        for (int j = 1; j <= w; j++)
        {
            cnt++;

            id[i][j] = cnt;
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (map[i][j] == '#')
            {
                continue;
            }

            if (map[i + 1][j] == '.')
            {
                floyd[id[i][j]][id[i + 1][j]] = 1;
            }

            if (map[i - 1][j] == '.')
            {
                floyd[id[i][j]][id[i - 1][j]] = 1;
            }

            if (map[i][j + 1] == '.')
            {
                floyd[id[i][j]][id[i][j + 1]] = 1;
            }

            if (map[i][j - 1] == '.')
            {
                floyd[id[i][j]][id[i][j - 1]] = 1;
            }
        }
    }

    for (int k = 1; k <= h * w; k++)
    {
        for (int i = 1; i <= h * w; i++)
        {
            for (int j = 1; j <= h * w; j++)
            {
                floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for (int i = 1; i <= h * w; i++)
    {
        for (int j = 1; j <= h * w; j++)
        {
            if (floyd[i][j] == 0x3f3f3f3f)
            {
                continue;
            }

            answer = std::max(answer, floyd[i][j]);
        }
    }

    printf("%d\n", answer);

    return 0;
}