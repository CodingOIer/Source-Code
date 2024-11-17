#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    std::sort(s + 1, s + 1 + n);
    printf("%s\n", strcmp(s + 1, "122333") == 0 ? "Yes" : "No");
    return 0;
}
