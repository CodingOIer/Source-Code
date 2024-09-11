#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e6 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' || s[i] == '2' || s[i] == '4' || s[i] == '8')
        {
            answer++;
        }
    }
    for (int i = 1; i <= n - 4; i++)
    {
        if (s[i] == '6' && s[i + 1] == '5' && s[i + 2] == '5' && s[i + 3] == '3' && s[i + 4] == '6')
        {
            answer++;
            s[i + 4] = '9';
        }
    }
    printf("%d\n", answer);
    return 0;
}