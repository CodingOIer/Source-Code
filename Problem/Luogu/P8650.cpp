#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN];
char s[MaxN];
std::stack<int> stack;
int calc(int l, int r)
{
    int res = 0;
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == 'x')
        {
            cnt++;
        }
        else if (s[i] == '(')
        {
            cnt += calc(i + 1, p[i] - 1);
            i = p[i];
        }
        else if (s[i] == '|')
        {
            res = std::max(res, cnt);
            cnt = 0;
        }
    }
    res = std::max(res, cnt);
    return res;
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
            p[i] = stack.top();
            p[stack.top()] = i;
            stack.pop();
        }
    }
    printf("%d\n", calc(1, n));
    return 0;
}