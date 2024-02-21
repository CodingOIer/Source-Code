#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
constexpr int MaxM = 1e3 + 5;
int n;
int l[MaxN];
int r[MaxN];
bool f[MaxM];
int calc(int id)
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        if (i == id)
        {
            continue;
        }
        for (int j = l[i]; j < r[i]; j++)
        {
            f[j] = true;
        }
    }
    int res = 0;
    for (int i = 0; i <= 1000; i++)
    {
        res += f[i] ? 1 : 0;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
    }
    int answer = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        int res = calc(i);
        answer = res > answer ? res : answer;
    }
    printf("%d\n", answer);
    return 0;
}