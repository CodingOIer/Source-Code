#include <cstdio>
#include <cstring>
const int MaxN = 1e3 + 5;
int t;
int n;
int x;
char s[MaxN];
char base[MaxN] = {"luoguluoguluoguluoguluoguluoguluoguluoguluoguluogu"};
char not_same(const char c)
{
    return 'a' + (c - 'a' + 1) % 26;
}
void solve()
{
    scanf("%d", &n);
    memcpy(s, base, sizeof(s));
    printf("%s\n", s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        for (int i = 0; i < x; i++)
        {
            printf("%c", s[i]);
        }
        for (int i = x; i < 50; i++)
        {
            s[i] = not_same(s[i]);
            printf("%c", s[i]);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}