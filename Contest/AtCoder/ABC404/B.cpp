#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN][MaxN];
char t[MaxN][MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", t[i] + 1);
    }
    int answer = 0x3f3f3f3f;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp += s[i][j] != t[i][j] ? 1 : 0;
        }
    }
    answer = std::min(answer, temp);
    temp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp += s[j][n - i + 1] != t[i][j] ? 1 : 0;
        }
    }
    answer = std::min(answer, temp + 3);
    temp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp += s[n - j + 1][i] != t[i][j] ? 1 : 0;
        }
    }
    answer = std::min(answer, temp + 1);
    temp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp += s[n - i + 1][n - j + 1] != t[i][j] ? 1 : 0;
        }
    }
    answer = std::min(answer, temp + 2);
    printf("%d\n", answer);
    return 0;
}