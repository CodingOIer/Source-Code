#include <algorithm>
#include <cstdio>
#include <cstring>
int cnt;
int n, m, c;
double think[55][205];
double click[205][205];
std::pair<double, int> answer[205];
int main()
{
    scanf("%d %d %d", &n, &m, &c);
    memset(think, -1.0, sizeof(think));
    for (int i = 1; i <= c; i++)
    {
        int user, movie;
        double point;
        scanf("%d %d %lf", &user, &movie, &point);
        think[user][movie] = point;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            if (i == j)
            {
                click[i][j] = 1;
                continue;
            }
            bool find = false;
            double difference = 0;
            for (int k = 1; k <= n; k++)
            {
                if (think[k][i] == think[k][i] && think[k][j] == think[k][j])
                {
                    find = true;
                    difference += (think[k][i] - think[k][j]) * (think[k][i] - think[k][j]);
                }
            }
            if (find)
            {
                click[i][j] = click[j][i] = 1 / (1 + difference);
            }
        }
    }
    int id;
    for (; scanf("%d", &id) == 1;)
    {
        cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            if (think[id][i] == think[id][i])
            {
                continue;
            }
            double p = 0, q = 0;
            for (int j = 1; j <= m; j++)
            {
                if (think[id][j] == think[id][j])
                {
                    p += click[i][j] * think[id][j];
                    q += click[i][j];
                }
            }
            cnt++;
            answer[cnt] = {p / q, i};
        }
        std::sort(answer + 1, answer + cnt + 1, [](const auto &x, const auto &y) { return x.first > y.first; });
        printf("Recommendations for user %d:\n", id);
        for (int i = 1; i <= 10 && i <= cnt; i++)
        {
            printf("%d %.3f\n", answer[i].second, answer[i].first);
        }
        printf("\n");
    }
    return 0;
}