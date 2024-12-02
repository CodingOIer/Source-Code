#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n, k;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int all = 0;
    for (int i = 1; i <= n; i++)
    {
        all += s[i] == '@' ? 1 : 0;
    }
    printf("%d\n", n - std::max(all - k, 0));
    return 0;
}
