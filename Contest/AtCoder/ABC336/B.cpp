#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int answer = 0;
    for (; n % 2 == 0;)
    {
        n /= 2;
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}