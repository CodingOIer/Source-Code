#include <cstdio>
#include <set>
int n;
std::set<int> set;
int main()
{
    n = 10;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        set.insert(x % 42);
    }
    printf("%zu", set.size());
    return 0;
}