#include "interaction.h"
#include <vector>
int n;
std::vector<int> v;
int main()
{
    n = get_num();
    for (int i = 0; i < n; i++)
    {
        int l, r;
        l = 0;
        r = 1e6;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            auto res = guess(i, mid);
            if (res < 0)
            {
                l = mid + 1;
            }
            else if (res == 0)
            {
                v.push_back(mid);
                break;
            }
            else if (res > 0)
            {
                r = mid - 1;
            }
        }
    }
    submit(v);
    return 0;
}