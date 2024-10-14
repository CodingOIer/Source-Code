#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#')
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}