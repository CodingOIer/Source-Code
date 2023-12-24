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
const int MaxN = 1e5 + 5;
const int MaxM = 3e6 + 5;
int t;
int n;
int q;
int cnt;
int p[MaxM];
int trie[MaxM][65];
char input[MaxM];
int num(char c)
{
    if ('a' <= c && c <= 'z')
    {
        return c - 'a';
    }
    else if ('A' <= c && c <= 'Z')
    {
        return 26 + c - 'A';
    }
    else if ('0' <= c && c <= '9')
    {
        return 52 + c - '0';
    }
    return -1;
}
void solve()
{
    cnt = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", input);
        int k = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            int c = num(input[i]);
            if (trie[k][c] == 0)
            {
                cnt++;
                trie[k][c] = cnt;
            }
            p[trie[k][c]]++;
            k = trie[k][c];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%s", input);
        int k;
        k = 0;
        int len;
        len = strlen(input);
        bool flag;
        flag = false;
        for (int i = 0; i < len; i++)
        {
            int c = num(input[i]);
            if (trie[k][c] == 0)
            {
                flag = true;
                break;
            }
            k = trie[k][c];
        }
        printf("%d\n", flag ? 0 : p[k]);
    }
    for (int i = 0; i <= cnt; i++)
    {
        p[i] = 0;
        for (int j = 0; j < 62; j++)
        {
            trie[i][j] = 0;
        }
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