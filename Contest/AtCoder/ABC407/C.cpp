#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 5e5 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    std::reverse(s + 1, s + 1 + n);
    int w = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (; s[i] - '0' != w;)
        {
            w++;
            w = w == 10 ? 0 : w;
            answer++;
        }
    }
    printf("%d\n", answer + n);
    return 0;
}