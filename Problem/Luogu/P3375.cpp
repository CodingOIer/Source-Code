#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
int to[MaxN][128];
char s[MaxN];
char t[MaxN];
void init(char *s)
{
    int m = strlen(s + 1);
    int last = 0;
    to[0][int(s[1])] = 1;
    for (int i = 1; i <= m - 1; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            if (s[i + 1] == j)
            {
                to[i][j] = i + 1;
            }
            else
            {
                to[i][j] = to[last][j];
            }
        }
        last = to[last][int(s[i + 1])];
    }
    for (int c = 0; c < 128; c++)
    {
        to[m][c] = to[last][c];
    }
}
std::vector<int> KMP(char *s, char *t)
{
    std::vector<int> res;
    int n, m;
    n = strlen(s + 1);
    m = strlen(t + 1);
    init(t);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c = to[c][int(s[i])];
        if (c == m)
        {
            res.push_back(i - m + 1);
        }
    }
    return res;
}
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    auto answer = KMP(s, t);
    for (const auto &val : answer)
    {
        printf("%d\n", val);
    }
    n = strlen(t + 1);
    int border = 0;
    printf("%d ", border);
    for (int i = 2; i <= n; i++)
    {
        border = to[border][int(t[i])];
        printf("%d ", border);
    }
    printf("\n");
    return 0;
}