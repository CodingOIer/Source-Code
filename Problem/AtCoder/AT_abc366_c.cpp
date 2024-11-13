#include <cstdio>
constexpr int MaxM = 1e6 + 5;
int n;
int answer;
int v[MaxM];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            answer += v[x] == 0 ? 1 : 0;
            v[x]++;
        }
        else if (op == 2)
        {
            scanf("%d", &x);
            answer -= v[x] == 1 ? 1 : 0;
            v[x]--;
        }
        else
        {
            printf("%d\n", answer);
        }
    }
    return 0;
}