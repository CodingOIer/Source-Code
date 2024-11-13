#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
constexpr int MaxN = 1e2 + 5;
int a, b;
class tree
{
  public:
    int x;
    std::vector<bool> oper;
    std::vector<tree *> expr;
    tree()
    {
        x = -1;
    }
    int value()
    {
        if (x != -1)
        {
            return x;
        }
        int res = expr[0]->value();
        for (int i = 0; i < oper.size(); i++)
        {
            if (oper[i])
            {
                if (res == 0)
                {
                    a++;
                }
                res = res && expr[i + 1]->value() ? 1 : 0;
            }
            else
            {
                if (res == 1)
                {
                    b++;
                }
                res = res || expr[i + 1]->value() ? 1 : 0;
            }
        }
        return res;
    }
};
int n;
int pair[MaxN];
tree *root;
char s[MaxN];
std::stack<int> stack;
void makeExprTree(tree *ptr, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '(')
        {
            tree *add_tree = new tree;
            makeExprTree(add_tree, i + 1, pair[i] - 1);
            i = pair[i];
            ptr->expr.push_back(add_tree);
        }
        else if (s[i] == '&')
        {
            ptr->oper.push_back(true);
        }
        else if (s[i] == '|')
        {
            ptr->oper.push_back(false);
        }
        else
        {
            tree *add_tree = new tree;
            add_tree->x = s[i] == '1' ? 1 : 0;
            ptr->expr.push_back(add_tree);
        }
    }
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            stack.push(i);
        }
        else if (s[i] == ')')
        {
            pair[i] = stack.top();
            pair[stack.top()] = i;
            stack.pop();
        }
    }
    root = new tree;
    makeExprTree(root, 1, n);
    printf("%d\n", root->value());
    printf("%d %d\n", a, b);
    return 0;
}