#include <algorithm>
#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e1 + 5;
int n;
int f[MaxN];
int main()
{
    n = 9;
    std::iota(f + 1, f + 1 + n, 1);
    for (;;)
    {
        int x, y, z;
        x = f[1] * 100 + f[2] * 10 + f[3];
        y = f[4] * 100 + f[5] * 10 + f[6];
        z = f[7] * 100 + f[8] * 10 + f[9];
        if (x == y / 2 && x == z / 3)
        {
            printf("%d %d %d\n", x, y, z);
        }
        if (!std::next_permutation(f + 1, f + 1 + n))
        {
            break;
        }
    }
    return 0;
}
