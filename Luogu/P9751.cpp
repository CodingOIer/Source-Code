#include <cstdio>
constexpr int MaxN = 1e4 + 5;
class edge
{
  public:
    int u, v, w;
    edge()
    {
        u = 0;
        v = 0;
        w = 0;
    }
};
int n, m, k;