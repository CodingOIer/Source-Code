#include "testlib.h"
#include <algorithm>
#include <cstdlib>
int main(int argc, char **argv)
{
    registerTestlibCmd(argc, argv);
    int q;
    inf.readInt();
    q = inf.readInt();
    for (int i = 1; i <= q; i++)
    {
        double x, y;
        x = ouf.readDouble();
        y = ans.readDouble();
        if (abs(x - y) / std::max(1.0, abs(y)) > 1e-6)
        {
            quitf(_wa, "Wrong Answer on line %d.", i);
        }
    }
    quitf(_ok, "AC, TQL.");
    return 0;
}
