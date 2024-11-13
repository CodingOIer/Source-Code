#include <cstdio>
int x;
int main()
{
    scanf("%d", &x);
    int answer = 0;
    for (; x != 0;)
    {
        x /= 2;
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}