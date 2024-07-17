#include <cstdio>
#include <set>
#include <stack>
constexpr int MaxN = 5e4 + 5;
int n, m;
std::set<int> set;
std::stack<int> stack;
int main()
{
    scanf("%d%d", &n, &m);
    set.insert(0);
    set.insert(n + 1);
    for (int i = 1; i <= m; i++)
    {
        char c = '\0';
        for (; !(c == 'D' || c == 'R' || c == 'Q');)
        {
            c = getchar();
        }
        if (c == 'D')
        {
            int x;
            scanf("%d", &x);
            set.insert(x);
            stack.push(x);
        }
        else if (c == 'R')
        {
            set.erase(stack.top());
            stack.pop();
        }
        else if (c == 'Q')
        {
            int x;
            scanf("%d", &x);
            if (set.find(x) != set.end())
            {
                printf("0\n");
            }
            else
            {
                auto l = set.lower_bound(x);
                auto r = l;
                l--;
                printf("%d\n", (*r) - (*l) - 1);
            }
        }
    }
    return 0;
}