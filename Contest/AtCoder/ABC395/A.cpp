#include <cstdio>
constexpr int MaxN = 1e2 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    bool suc = true;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        suc &= p[i - 1] < p[i];
    }
    printf("%s\n", suc ? "Yes" : "No");
    return 0;
}
