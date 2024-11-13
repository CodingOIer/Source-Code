#include <cstdio>
long long x, y;
long long once[15];
long long answer[15];
void addOnce(long long x)
{
    for (int i = 1; i <= 6; i++)
    {
        once[x % 10]++;
        x /= 10;
    }
}
void addAnswer(long long x, long long cnt = 1)
{
    for (; x != 0;)
    {
        answer[x % 10] += cnt;
        x /= 10;
    }
}
void print()
{
    for (int i = 0; i <= 9; i++)
    {
        printf("%lld ", answer[i]);
    }
    printf("\n");
}
int main()
{
    scanf("%lld%lld", &x, &y);
    for (long long i = 0; i <= 999999; i++)
    {
        addOnce(i);
    }
    for (; x % 1000000 != 0 && x <= y;)
    {
        addAnswer(x);
        x++;
    }
    for (; y % 1000000 != 999999 && y >= x;)
    {
        addAnswer(y);
        y--;
    }
    if (x > y)
    {
        print();
        return 0;
    }
    long long cnt = (y - x + 1) / 1000000;
    for (int i = 0; i <= 9; i++)
    {
        answer[i] += cnt * once[i];
    }
    x /= 1000000;
    y /= 1000000;
    for (; x <= y;)
    {
        addAnswer(x, 1000000);
        x++;
    }
    print();
    return 0;
}