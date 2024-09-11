#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int main()
{
    scanf("%d", &n);
    int last = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        int money = std::min(50, x - last);
        last = x;
        answer += money / 8;
        last -= money % 8;
    }
    printf("%d\n", answer);
    return 0;
}