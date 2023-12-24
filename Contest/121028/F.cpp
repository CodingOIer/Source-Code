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
const int MaxN = 5e2 + 5;
int n, m;
int answer;
char s[MaxN][MaxN];
int main()
{
    scanf("%d%d%*d%*d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", (s[i] + 1));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '.')
            {
                continue;
            }
            bool f;
            int how;
            how = 0;
            f = true;
            for (int k = i - 1; k >= 1; k--)
            {
                if (s[k][j] != s[i][j] && s[k][j] != '.')
                {
                    f = false;
                }
            }
            how += f;
            f = true;
            for (int k = i + 1; k <= n; k++)
            {
                if (s[k][j] != s[i][j] && s[k][j] != '.')
                {
                    f = false;
                }
            }
            how += f;
            f = true;
            for (int k = j - 1; k >= 1; k--)
            {
                if (s[i][k] != s[i][j] && s[i][k] != '.')
                {
                    f = false;
                }
            }
            how += f;
            f = true;
            for (int k = j + 1; k <= m; k++)
            {
                if (s[i][k] != s[i][j] && s[i][k] != '.')
                {
                    f = false;
                }
            }
            how += f;
            f = true;
            if (how >= 3)
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}