#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
int main()
{
    freopen("std.in", "w", stdout);
    int t = 5;
    printf("%d\n", t);
    for (int i = 1; i <= t; i++)
    {
        printf("%u %u %u\n", rnd() % 6, rnd() % 6, rnd() % 6);
    }
    return 0;
}