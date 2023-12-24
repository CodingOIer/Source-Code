#include <bits/stdc++.h>
using namespace std;
struct str
{
    int t, x, y;
};
const int MaxN = 1e5 + 5;
int n;
int len, time_;
str p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &p[i].t, &p[i].x, &p[i].y);
    }
    for (int i = 1; i <= n; i++)
    {
        len = abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y);
        time_ = (p[i].t - p[i - 1].t);
        if (len > time_ || (abs(len - time_) % 2 != 0))
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}