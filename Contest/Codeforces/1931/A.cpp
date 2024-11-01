#include <cstdio>
int n;
inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int k = 1; k <= 26; k++)
            {
                if (i + j + k == n)
                {
                    printf("%c%c%c\n", 'a' + i - 1, 'a' + j - 1, 'a' + k - 1);
                    return;
                }
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}