#include <bitset>
#include <cstdio>
#include <vector>
constexpr int MaxN = 2e3 + 5;
int n;
int answer;
char s[MaxN];
std::bitset<MaxN> f[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = (s[j] - '0' == 1 ? true : false);
        }
        f[i][i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[j][i])
            {
                f[j] |= f[i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[i][j])
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}