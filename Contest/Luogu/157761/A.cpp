#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
char a[MaxN];
char b[MaxN];
char c[MaxN];
char d[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    scanf("%s", d);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > c[i] || (a[i] == c[i] && b[i] > d[i]))
        {
            std::swap(a[i], c[i]);
            std::swap(b[i], d[i]);
        }
    }
    printf("%s\n", b);
    return 0;
}