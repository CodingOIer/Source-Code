#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    long long days = (n + x - 1) + (m + y - 1) - 1;
    long long minRaindrops = (n / x) * (m / y) * k;

    cout << days << " " << minRaindrops << endl;

    return 0;
}
