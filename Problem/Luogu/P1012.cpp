#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
const int MaxN = 25;
int n;
std::string p[MaxN];
bool cmp(const std::string &x, const std::string &y)
{
    return ((x + y) > (y + x));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
    }
    std::sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        printf("%s", p[i].c_str());
    }
    printf("\n");
    return 0;
}