#include <cstdio>
#include <stack>
#include <tuple>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
bool check(int limit)
{
    std::stack<std::tuple<int, int>> stack;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] <= p[i - 1])
        {
            if (limit == 1)
            {
                return false;
            }
            for (; !stack.empty();)
            {
                auto [w, val] = stack.top();
                if (w <= p[i])
                {
                    break;
                }
                stack.pop();
            }
            if (stack.empty())
            {
                stack.push({p[i], 1});
            }
            else
            {
                for (int k = p[i]; k >= 0; k--)
                {
                    if (stack.empty())
                    {
                        stack.push({k, 1});
                        break;
                    }
                    auto [w, val] = stack.top();
                    if (w != k)
                    {
                        stack.push({k, 1});
                        break;
                    }
                    else if (val + 1 != limit)
                    {
                        stack.pop();
                        stack.push({w, val + 1});
                        break;
                    }
                    else
                    {
                        stack.pop();
                    }
                }
                auto [w, l] = stack.top();
                if (w == 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int l, r;
    l = 1;
    r = n;
    int res = n;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n", res);
    return 0;
}