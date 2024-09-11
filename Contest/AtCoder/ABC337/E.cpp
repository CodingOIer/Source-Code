#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN];
char report[MaxN];
std::vector<int> answer[MaxN];
int main()
{
    scanf("%d", &n);
    int temp = n - 1;
    int cnt = 0;
    for (; temp != 0;)
    {
        cnt++;
        temp /= 2;
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] = i - 1;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j] % 2 == 1)
            {
                answer[i].push_back(j);
            }
            p[j] /= 2;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d", (int)(answer[i].size()));
        for (int j = 0; j < (int)(answer[i].size()); j++)
        {
            printf(" %d", answer[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
    scanf("%s", report);
    int len = strlen(report);
    int answer = 0;
    for (int i = 0; i < len; i++)
    {
        answer += (1 << i) * (report[i] == '1' ? 1 : 0);
    }
    printf("%d\n", answer + 1);
    fflush(stdout);
    return 0;
}