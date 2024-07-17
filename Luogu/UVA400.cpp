#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
constexpr int MaxN = 105;
constexpr int MaxM = 65;
int n;
char s[MaxM];
char output[MaxN][MaxM];
std::vector<std::string> v;
void solve()
{
    for (int i = 0; i < MaxN; i++)
    {
        for (int j = 0; j < MaxM; j++)
        {
            output[i][j] = '\0';
        }
    }
    v.clear();
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        l = std::max(l, int(strlen(s)));
        v.push_back(s);
    }
    std::sort(v.begin(), v.end());
    int x, y;
    x = 0;
    y = 0;
    int li = n / (62 / (l + 2)) + (n % (62 / (l + 2)) != 0 ? 1 : 0);
    for (auto k : v)
    {
        strcpy(output[x] + y, k.c_str());
        x++;
        if (x == li)
        {
            x = 0;
            y += l + 2;
        }
    }
    for (int i = 1; i <= 60; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < li; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            printf("%c", output[i][j] == '\0' ? ' ' : output[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    for (; scanf("%d", &n) == 1;)
    {
        solve();
    }
    return 0;
}