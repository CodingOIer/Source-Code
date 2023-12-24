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

const int MaxN = 5e5 + 5;

class str
{
  public:
    char c;
    int edit;
};

int n, q;
int t, x;
int edit;
int mode;

char c;
char s[MaxN];

str p[MaxN];

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 1; i <= n; i++)
    {
        p[i].c = s[i - 1];
        p[i].edit = 0;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d %d %c", &t, &x, &c);
        if (t == 1)
        {
            p[x].c = c;
            p[x].edit = edit;
        }
        else if (t == 2)
        {
            edit++;
            mode = 0;
        }
        else if (t == 3)
        {
            edit++;
            mode = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i].edit >= edit)
        {
            printf("%c", p[i].c);
        }
        else
        {
            if (mode == 0)
            {
                printf("%c", tolower(p[i].c));
            }
            else if (mode == 1)
            {
                printf("%c", toupper(p[i].c));
            }
        }
    }
    printf("\n");
    return 0;
}