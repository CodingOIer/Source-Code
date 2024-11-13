#include <cstdio>
int n;
bool check10(int x)
{
    if (x == 0)
    {
        return true;
    }
    if (x % 10 == 7)
    {
        return false;
    }
    return check10(x / 10);
}
bool check8(int x)
{
    if (x == 0)
    {
        return true;
    }
    if (x % 8 == 7)
    {
        return false;
    }
    return check8(x / 8);
}
int main()
{
    scanf("%d", &n);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check8(i) && check10(i))
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}