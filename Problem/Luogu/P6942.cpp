#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e2 + 5;
class str
{
  public:
    char s[MaxN];
    char c[MaxN];
    bool l, r;
};
int n;
int len;
str p[MaxN];
char p[MaxN];
std::unordered_map<std::string, bool> left;
std::unordered_map<std::string, bool> right;
int main()
{
    for (; scanf("%s", p[n + 1].s) == 1;)
    {
        n++;
        len = strlen(p[n].s);
        for (int i = 0, j = 0; i < len; i++, j++)
        {
            if (((i == 0 && p[0] == ',') || (i == len - 1 && p[len - 1] == ',')))
            {
                continue;
            }
            else
            {
                p[i].c[j] = p[i];
                p[i].c[j + 1] = '\0';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i].s[0] == ',')
        {
            p[i].l = true;
            left[(p[i].c)] = true;
        }
        if (p[i].s[strlen(p[i].s) - 1] == ',')
        {
            p[i].r = true;
            right[(p[i].c)] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (left[(p[i].c)] && !p[i].l && i != 1)
        {
            printf(",");
        }
        printf("%s", p[i].s);
        if (right[(p[i].c)] && !p[i].r && i != n)
        {
            printf(",");
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}