#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int sum;
int level;

double t;
double health;

int power(int x, int y)
{
    int res;
    res = 1;
    for (; y != 0;)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    health = 10;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%d", &t, &x);
        health = min(health - t, 10.0);
        if (health > 0)
        {
            sum += x;
        }
        else
        {
            break;
        }
    }
    for (;;)
    {
        if (sum >= power(2, level))
        {
            sum -= power(2, level);
            level++;
        }
        else
        {
            break;
        }
    }
    printf("%d %d\n", level, sum);
    return 0;
}