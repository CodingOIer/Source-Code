#include <algorithm>
#include <cstdio>
#include <vector>
int n;
std::vector<int> v;
int main()
{
    scanf("%d", &n);
    for (; n != 1;)
    {
        v.push_back(n);
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
    }
    v.push_back(1);
    std::reverse(v.begin(), v.end());
    for (auto val : v)
    {
        printf("%d ", val);
    }
    return 0;
}