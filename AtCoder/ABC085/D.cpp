#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
int n, h;

int Max, ans;
int x;
int b[MaxN];
int main()
{
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> b[i];
        Max = max(Max, x);
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    int p = 1;
    while (h > 0 && p <= n && b[p] > Max)
    {
        h -= b[p];
        ans++;
        p++;
    }
    if (h > 0)
    {
        ans += ceil(h / (Max * 1.00));
    }
    cout << ans;
}