#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n, k;
char s[MaxN];
char t[MaxN];
std::vector<char> v;
std::vector<char> c;
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        v.push_back(s[i]);
        if (v.size() >= 3)
        {
            if ((v[v.size() - 1] == 'C' && v[v.size() - 2] == 'B' && v[v.size() - 3] == 'A') ||
                (v[v.size() - 1] == 'B' && v[v.size() - 2] == 'A' && v[v.size() - 3] == 'C') ||
                (v[v.size() - 1] == 'A' && v[v.size() - 2] == 'C' && v[v.size() - 3] == 'B'))
            {
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
        }
    }
    scanf("%d", &k);
    for (int _ = 1; _ <= k; _++)
    {
        c.clear();
        scanf("%s", t + 1);
        for (int i = 1; i <= n; i++)
        {
            c.push_back(t[i]);
            if (c.size() >= 3)
            {
                if ((c[c.size() - 1] == 'C' && c[c.size() - 2] == 'B' && c[c.size() - 3] == 'A') ||
                    (c[c.size() - 1] == 'B' && c[c.size() - 2] == 'A' && c[c.size() - 3] == 'C') ||
                    (c[c.size() - 1] == 'A' && c[c.size() - 2] == 'C' && c[c.size() - 3] == 'B'))
                {
                    c.pop_back();
                    c.pop_back();
                    c.pop_back();
                }
            }
        }
        if (v.size() != c.size())
        {
            printf("no\n");
            continue;
        }
        bool suc = true;
        for (int i = 0; i < int(v.size()); i++)
        {
            if (v[i] != c[i])
            {
                suc = false;
                break;
            }
        }
        printf("%s\n", suc ? "yes" : "no");
    }
    return 0;
}
