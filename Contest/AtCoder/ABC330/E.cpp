#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
const int MaxN = 2e5 + 5;
int n, q;
int k, x;
int p[MaxN];
std::set<int> answer;
std::map<int, int> map;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= 2 * n + 5; i++)
    {
        answer.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        answer.erase(p[i]);
        map[p[i]]++;
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &k, &x);
        map[p[k]]--;
        if (map[p[k]] == 0)
        {
            answer.insert(p[k]);
        }
        answer.erase(x);
        map[x]++;
        p[k] = x;
        printf("%d\n", *answer.begin());
    }
    return 0;
}