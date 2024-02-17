#include <cstdio>
#include <random>
std::mt19937 rnd(std::random_device{}());
int main()
{
    int n, m, k;
    n = rnd() % 10 + 1;
    m = rnd() % 10 + 1;
    k = rnd() % 20 + 1;
    for (; n == m;)
    {
        n = rnd() % 10 + 1;
        m = rnd() % 10 + 1;
    }
    freopen("test.in", "w", stdout);
    printf("%d %d %d\n", n, m, k);
    return 0;
}