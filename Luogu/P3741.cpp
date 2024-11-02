#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
bool can[MaxN];
inline int calc()
{
    int res = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            res++;
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int answer = calc();
    for (int i = 1; i <= n; i++)
    {
        char backup = s[i];
        s[i] = 'V';
        answer = std::max(answer, calc());
        s[i] = 'K';
        answer = std::max(answer, calc());
        s[i] = backup;
    }
    printf("%d\n", answer);
    return 0;
}