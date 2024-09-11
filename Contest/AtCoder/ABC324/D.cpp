#include <cstdio>
const int MaxN = 15;
int n;
int answer;
int have[MaxN];
char s[MaxN];
bool check(long long x)
{
    int need[MaxN] = {};
    for (; x > 0;)
    {
        need[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (!(need[i] == have[i] || (i == 0 && have[i] > need[i])))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        have[s[i] - '0']++;
    }
    for (long long i = 0; i * i <= 1e14; i++)
    {
        if (check(i * i))
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}