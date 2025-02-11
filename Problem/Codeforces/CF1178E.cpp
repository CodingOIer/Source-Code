#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e6 + 5;
int n;
char s[MaxN];
std::vector<char> v;
std::vector<char> k;
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int l, r;
    l = 1;
    r = n;
    for (; l < r;)
    {
        if (l + 3 <= r)
        {
            if (s[l] == s[r])
            {
                v.push_back(s[l]);
                k.push_back(s[l]);
            }
            else if (s[l] == s[r - 1])
            {
                v.push_back(s[l]);
                k.push_back(s[l]);
            }
            else if (s[l + 1] == s[r])
            {
                v.push_back(s[l + 1]);
                k.push_back(s[l + 1]);
            }
            else if (s[l + 1] == s[r - 1])
            {
                v.push_back(s[l + 1]);
                k.push_back(s[l + 1]);
            }
        }
        else
        {
            v.push_back(s[l]);
            break;
        }
        l += 2;
        r -= 2;
    }
    std::reverse(k.begin(), k.end());
    for (const auto &val : v)
    {
        printf("%c", val);
    }
    for (const auto &val : k)
    {
        printf("%c", val);
    }
    return 0;
}
