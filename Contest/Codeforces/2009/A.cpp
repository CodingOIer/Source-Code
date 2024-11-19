#include <algorithm>
#include <cstdio>
int a, b;
inline void solve()
{
    scanf("%d%d", &a, &b);
    int answer = 0x7f7f7f7f;
    for (int c = -100; c <= 100; c++)
    {
        answer = std::min(answer, (c - a) + (b - c));
    }
    printf("%d\n", answer);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
