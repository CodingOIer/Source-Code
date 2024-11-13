#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
std::map<int, int> map;
int magic(int x)
{
    if (x < 10)
    {
        return x;
    }
    if (map.count(x))
    {
        return map[x];
    }
    std::vector<int> v;
    int last = x % 10;
    x /= 10;
    for (; x != 0;)
    {
        v.push_back(abs(x % 10 - last));
        last = x % 10;
        x /= 10;
    }
    int res = 0;
    std::reverse(v.begin(), v.end());
    for (auto val : v)
    {
        res = res * 10 + val;
    }
    int r = magic(res);
    map[x] = r;
    return r;
}
int main()
{
    freopen("list.txt", "w", stdout);
    int block = 1234567;
    int res = 0;
    for (int i = 1; i <= 1e9; i++)
    {
        res += magic(i) == 7 ? 1 : 0;
        if (i % block == 0)
        {
            printf("%d,", res);
            fprintf(stderr, "%d\n", i);
        }
    }
    return 0;
}