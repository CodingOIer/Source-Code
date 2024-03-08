#include <cstdio>
constexpr int MaxN = 5e5 + 5;
class node
{
    int x;
    int max;
    int sum;
    int l_max;
    int r_max;
    node()
    {
        x = 0;
        max = 0;
        sum = 0;
        l_max = 0;
        r_max = 0;
    }
    friend node operator+(const node &__x, const node &__y)
    {
        node res;
    }
    void update()
    {
        max = x;
        sum = x;
        l_max = x;
        r_max = x;
    }
};
int n, m;
int p[MaxN];
node tree[MaxN * 4];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    return 0;
}