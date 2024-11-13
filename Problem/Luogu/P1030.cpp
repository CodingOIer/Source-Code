#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
char t[MaxN];
void solve(int x, int y, int l, int r)
{
    if (l == r)
    {
        printf("%c", t[r]);
        return;
    }
    else if (x > y || l > r)
    {
        return;
    }
    int to = -1;
    for (int i = x; i <= y; i++)
    {
        if (s[i] == t[r])
        {
            to = i;
            break;
        }
    }
    printf("%c", t[r]);
    solve(x, to - 1, l, l + (to - x) - 1);
    solve(to + 1, y, l + (to - x), r - 1);
}
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    solve(1, n, 1, n);
    return 0;
}