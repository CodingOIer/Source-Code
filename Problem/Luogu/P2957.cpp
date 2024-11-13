#include <algorithm>
#include <cstdio>
#include <cstring>
constexpr int MaxN = 2e5 + 5;
int n, m;
char s[MaxN];
char t[MaxN];
inline bool check(int l1, int l2, int len)
{
    if (l1 <= 0 || l2 <= 0 || l1 + len - 1 > n || l2 + len - 1 > m)
    {
        return false;
    }
    for (int app = 0; app < len; app++)
    {
        if (s[l1 + app] != t[l2 + app])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    int answer = 0;
    for (int i = 1; i <= std::min(n, m); i++)
    {
        if (check(1, m - i + 1, i) || check(n - i + 1, 1, i))
        {
            answer = std::max(answer, i);
        }
    }
    printf("%d\n", answer);
    return 0;
}