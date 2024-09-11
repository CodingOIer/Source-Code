#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
int x;
int n, l;
int answer;
int main()
{
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        answer += x >= l ? 1 : 0;
    }
    printf("%d\n", answer);
    return 0;
}