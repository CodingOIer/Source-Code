#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, k;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int answer = 0;
    for (int i = k; i <= n; i++)
    {
        bool f = true;
        for (int j = i - k + 1; j <= i; j++)
        {
            f &= s[j] == 'O';
        }
        if (f)
        {
            answer++;
            for (int j = i - k + 1; j <= i; j++)
            {
                s[j] = 'X';
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}