#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
int check(int l, int r)
{
    int cnt[128] = {0};
    int res = 0;
    for (int i = l; i <= r; i++)
    {
        cnt[s[i]]++;
        if (cnt[s[i]] > cnt[res])
        {
            res = s[i];
        }
    }
    return cnt[res] <= (r - l + 1) / 2;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int answer = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            if (check(l, r))
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}