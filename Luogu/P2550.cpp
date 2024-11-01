#include <cstdio>
#include <map>
constexpr int MaxN = 1e2 + 5;
int n;
int answer[MaxN];
std::map<int, bool> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 7; i++)
    {
        int x;
        scanf("%d", &x);
        map[x] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= 7; j++)
        {
            int x;
            scanf("%d", &x);
            if (map[x])
            {
                cnt++;
            }
        }
        answer[cnt]++;
    }
    for (int i = 7; i >= 1; i--)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}