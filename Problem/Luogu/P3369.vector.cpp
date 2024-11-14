#include <algorithm>
#include <cstdio>
#include <vector>
int n;
std::vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1)
        {
            v.insert(std::lower_bound(v.begin(), v.end(), x), x);
        }
        else if (op == 2)
        {
            v.erase(std::lower_bound(v.begin(), v.end(), x));
        }
        else if (op == 3)
        {
            printf("%td\n", std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1);
        }
        else if (op == 4)
        {
            printf("%d\n", v[x - 1]);
        }
        else if (op == 5)
        {
            printf("%d\n", *(std::lower_bound(v.begin(), v.end(), x) - 1));
        }
        else if (op == 6)
        {
            printf("%d\n", *std::upper_bound(v.begin(), v.end(), x));
        }
    }
    return 0;
}
