#include <cstdio>
constexpr int MaxN = 3e5 + 5;
int n, limit;
int main()
{
    scanf("%d%d", &n, &limit);
    for (int i = 1; i <= n; i++)
    {
        char op = '\0';
        int x;
        for (; !(op == 'I' || op == 'A' || op == 'S' || op == 'F');)
        {
            op = getchar();
        }
        scanf("%d", &x);
    }
    return 0;
}