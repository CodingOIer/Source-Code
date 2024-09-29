#include <cstdio>
#include <cstdlib>
constexpr int MaxN = 2e2 + 5;
int w[128];
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    for (int i = 1; i <= 26; i++)
    {
        w[s[i]] = i;
    }
    int r = 0;
    for (int i = 'A'; i < 'Z'; i++)
    {
        r += abs(w[i + 1] - w[i]);
    }
    printf("%d\n", r);
    return 0;
}