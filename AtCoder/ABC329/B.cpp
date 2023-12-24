#include <cstdio>
#define max(a, b) (a > b ? a : b)
const int MaxN = 1e2 + 5;
int n;
int p[MaxN];
int end;
int answer;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        answer = max(answer, p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != answer)
        {
            end = max(end, p[i]);
        }
    }
    printf("%d\n", end);
    return 0;
}