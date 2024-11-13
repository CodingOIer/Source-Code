#include <cstdio>
#include <cstring>
#include <stack>
constexpr int MaxN = 5e1 + 5;
int n;
char s[MaxN];
std::stack<int> stack;
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    return 0;
}