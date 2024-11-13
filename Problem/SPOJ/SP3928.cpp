#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int Mod = 1e9 + 7;
int x, y;
long long once[15];
long long answer[15];
void addOnce(int x)
{
    for (int i = 1; i <= 4; i++)
    {
        once[x % 10]++;
        x /= 10;
    }
}
void addAnswer(int x, int cnt = 1)
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
void solve()
{
    memset(answer, 0, sizeof(answer));
    for (; x % 10000 != 0 && x <= y;)
    {
        addAnswer(x);
        x++;
    }
    for (; y % 10000 != 9999 && y >= x;)
    {
        addAnswer(y);
        y--;
    }
    if (x > y)
    {
        print();
        return;
    }
    int cnt = (y - x + 1) / 10000;
    for (int i = 0; i <= 9; i++)
    {
        answer[i] += cnt * once[i];
    }
    x /= 10000;
    y /= 10000;
    for (; x <= y;)
    {
        addAnswer(x, 10000);
        x++;
    }
    print();
}
int main()
{
    for (int i = 0; i <= 9999; i++)
    {
        addOnce(i);
    }
    for (;;)
    {
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0)
        {
            break;
        }
        if (x > y)
        {
            std::swap(x, y);
        }
        solve();
    }
    return 0;
}