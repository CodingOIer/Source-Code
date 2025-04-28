#include <cctype>
#include <cstdio>
int n;
int answer;
int read()
{
    long long res = 0;
    int f = 1;
    char ch = '\0';
    for (;;)
    {
        ch = getchar_unlocked();
        if (std::isdigit(ch))
        {
            res = ch ^ 48;
            break;
        }
        if (ch == '-')
        {
            f = -1;
        }
    }
    for (;;)
    {
        ch = getchar_unlocked();
        if (std::isdigit(ch))
        {
            res = res * 10 + (ch ^ 48);
        }
        else
        {
            break;
        }
    }
    return res * f;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        answer += x;
    }
    printf("%d\n", answer);
    return 0;
}