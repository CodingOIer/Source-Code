#include <cstdio>
int x;
int answer;
int main()
{
    scanf("%d", &x);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            answer += i * j == x ? 0 : i * j;
        }
    }
    printf("%d\n", answer);
    return 0;
}
