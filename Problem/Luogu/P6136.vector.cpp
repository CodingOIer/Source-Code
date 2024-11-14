#include <algorithm>
#include <cstdio>
#include <vector>
int n, m;
std::vector<int> v;
int main()
{
    scanf("%d%d", &n, &m);
    int last = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v.insert(std::lower_bound(v.begin(), v.end(), x), x);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        x ^= last;
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
            answer ^= last = std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
        }
        else if (op == 4)
        {
            answer ^= last = v[x - 1];
        }
        else if (op == 5)
        {
            answer ^= last = *(std::lower_bound(v.begin(), v.end(), x) - 1);
        }
        else if (op == 6)
        {
            answer ^= last = *std::upper_bound(v.begin(), v.end(), x);
        }
    }
    printf("%d\n", answer);
    return 0;
}
