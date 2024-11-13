#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int t;
int n;
char s[MaxN];
char k[MaxN];
std::vector<int> a;
std::vector<int> b;
void solve()
{
    a.clear();
    b.clear();
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", k + 1);
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i + 1])
        {
            a.push_back(i);
        }
        if (k[i] != k[i + 1])
        {
            b.push_back(i);
        }
    }
    if (s[n] != k[n])
    {
        a.push_back(n);
    }
    std::reverse(b.begin(), b.end());
    printf("%zu", a.size() + b.size());
    for (auto x : a)
    {
        printf(" %d", x);
    }
    for (auto x : b)
    {
        printf(" %d", x);
    }
    printf("\n");
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