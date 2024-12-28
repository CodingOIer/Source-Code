#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e5 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    bool preZero = false;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            if (preZero)
            {
                answer++;
            }
            preZero ^= true;
        }
        else
        {
            answer += preZero ? 1 : 0;
            preZero = false;
            answer++;
        }
    }
    answer += preZero ? 1 : 0;
    printf("%d", answer);
    return 0;
}
