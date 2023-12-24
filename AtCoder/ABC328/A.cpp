#include <cstdio>
const int MaxN = 1e5 + 5;
int n, x;
int input;
int answer;
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        answer += input <= x ? input : 0;
    }
    printf("%d\n", answer);
    return 0;
}