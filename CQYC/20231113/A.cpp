#include <cstdio>
#include <map>
#include <set>
const int MaxN = 1e5 + 5;
int n;
int x;
std::set<int> set;
std::map<int, int> map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        map[x]++;
        set.insert(x);
    }
    for (int x : set)
    {
        if (map[x] % 2 == 1)
        {
            printf("Alice\n");
            return 0;
        }
    }
    printf("Bob\n");
    return 0;
}