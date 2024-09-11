#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> colors(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    vector<long long> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (colors[i - 1] == colors[j])
            {
                continue;
            }
            dp[i] = max(dp[i], dp[j] + values[colors[i - 1] - 1]);
        }
    }

    if (dp[n] < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[n] << endl;
    }

    return 0;
}
