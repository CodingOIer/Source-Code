#include <algorithm>
#include <cstdio>
#include <numeric>
constexpr int MaxN = 1e1 + 5;
int n;
int p[MaxN];
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    std::iota(p + 1, p + 1 + n, 1);
    int answer = 0;
    for (;;)
    {
        answer++;
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            f &= (s[i] ^ 48) == p[i];
        }
        if (f)
        {
            break;
        }
        if (!std::next_permutation(p + 1, p + 1 + n))
        {
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}