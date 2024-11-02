#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    char last = '\0';
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        scanf(" ");
        scanf("%c", &ch);
        if (ch != last)
        {
            last = ch;
            answer++;
        }
    }
    printf("%d\n", answer + 1);
    return 0;
}