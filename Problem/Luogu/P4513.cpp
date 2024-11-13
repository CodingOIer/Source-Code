#include <algorithm>
#include <cstdio>
constexpr int MaxN = 5e5 + 5;
class node
{
  public:
    int x;
    int max;
    int sum;
    int l_max;
    int r_max;
    bool son;
    node()
    {
        x = 0;
        max = 0;
        sum = 0;
        l_max = 0;
        r_max = 0;
        son = false;
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
void build(int c, int s, int t)
{
    if (s == t)
    {
        tree[c].x = p[s];
        tree[c].son = true;
        tree[c].update();
        return;
    }
    int mid = (s + t) / 2;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    return 0;
}