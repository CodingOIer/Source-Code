#include <cstdio>
#include <regex>
constexpr int MaxN = 1e5 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    printf("%s\n", std::regex_match(s, std::regex("^(dream(er)?|erase(r)?)?*$")) ? "YES" : "NO");
    return 0;
}