#include <algorithm>
#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int one[MaxN];
int two[MaxN];
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cnt = 0;
    char last = -1;
    for (int i = 1; i <= n; i++)
    {
        if (last != s[i])
        {
            last = s[i];
            cnt = 0;
        }
        cnt++;
        if (last == '1')
        {
            one[i] = cnt;
        }
    }
    cnt = 0;
    last = -1;
    for (int i = n; i >= 1; i--)
    {
        if (last != s[i])
        {
            last = s[i];
            cnt = 0;
        }
        cnt++;
        if (last == '2')
        {
            two[i] = cnt;
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != '/')
        {
            continue;
        }
        if (i == 1 || i == n)
        {
            answer = std::max(1, answer);
            continue;
        }
        answer = std::max(1 + std::min(one[i - 1], two[i + 1]) * 2, answer);
    }
    printf("%d\n", answer);
    return 0;
}
