#include <cstdio>
#include <cstring>
#include <stack>
int n;
char op[15];
void solve()
{
    scanf("%d", &n);
    std::stack<unsigned long long> stack;
    for (int i = 1; i <= n; i++)
    {
        scanf(" ");
        scanf("%s", op);
        if (strcmp(op, "push") == 0)
        {
            unsigned long long x;
            scanf("%llu", &x);
            stack.push(x);
        }
        else if (strcmp(op, "pop") == 0)
        {
            if (stack.empty())
            {
                printf("Empty\n");
            }
            else
            {
                stack.pop();
            }
        }
        else if (strcmp(op, "query") == 0)
        {
            if (stack.empty())
            {
                printf("Anguei!\n");
            }
            else
            {
                printf("%llu\n", stack.top());
            }
        }
        else if (strcmp(op, "size") == 0)
        {
            printf("%zu\n", stack.size());
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}