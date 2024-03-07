#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e4 + 5;
char temp[MaxN];
char result[MaxN];
char command[MaxN];
long long n;
inline int getLen(long long x)
{
    int res = 0;
    for (; x != 0;)
    {
        res++;
        x /= 10;
    }
    return res;
}
void solve()
{
    temp[0] = 0;
    result[0] = 0;
    command[0] = 0;
    scanf("%lld", &n);
    sprintf(command, "factor %lld", n);
    FILE *pipe = popen(command, "r");
    for (; fgets(temp, sizeof(temp), pipe);)
    {
        sprintf(result, "%s%s", result, temp);
    }
    int len = getLen(n);
    int space = 0;
    int s_len = strlen(result);
    for (int i = 0; i < s_len; i++)
    {
        space += result[i] == ' ' ? 1 : 0;
    }
    if (space == 1)
    {
        printf("Prime\n");
    }
    else
    {
        long long answer = 0;
        for (int i = len + 2; i < s_len - 1; i++)
        {
            if (result[i] == ' ')
            {
                answer = 0;
                continue;
            }
            answer = answer * 10 + result[i] - '0';
        }
        printf("%lld\n", answer);
    }
    fclose(pipe);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}