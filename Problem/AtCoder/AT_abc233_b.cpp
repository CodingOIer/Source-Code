#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int l, r;
char s[MaxN];
int main()
{
    scanf("%d%d", &l, &r);
    scanf("%s", s + 1);
    std::reverse(s + l, s + r + 1);
    printf("%s", s + 1);
    return 0;
}