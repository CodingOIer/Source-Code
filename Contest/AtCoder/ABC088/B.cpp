#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e2 + 5;
int n;
int b[MaxN];
int first;
int second;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(b + 1, b + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        if ((n - i) % 2 == 0)
        {
            first += b[i];
        }
        else
        {
            second += b[i];
        }
    }
    printf("%d\n", first - second);
    return 0;
}