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
const int MaxM = 1e4 + 5;
int t;
int n;
int len;
int Accepted;
char word_std[MaxM][MaxN];
char word_user[MaxM][MaxN];
int main()
{
    for (;;)
    {
        std::cin.getline(word_std[n + 1], MaxN);
        if (!strcmp(word_std[n + 1], "EFO"))
        {
            break;
        }
        len = strlen(word_std[n + 1]);
        n++;
        for (int i = 0, j = 0; i <= len; i++)
        {
            if (word_std[n][i] == '<')
            {
                j--;
            }
            else
            {
                j++;
                word_std[n][j] = word_std[n][i];
            }
        }
    }
    n = 0;
    for (;;)
    {
        std::cin.getline(word_user[n + 1], MaxN);
        if (!strcmp(word_user[n + 1], "EFO"))
        {
            break;
        }
        len = strlen(word_std[n + 1]);
        n++;
        for (int i = 0, j = 0; i <= len; i++)
        {
            if (word_user[n][i] == '<')
            {
                j--;
            }
            else
            {
                j++;
                word_user[n][j] = word_user[n][i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        len = strlen(word_std[i]);
        for (int j = 0; j < len; j++)
        {
            if (word_std[i][j] == word_user[i][j])
            {
                Accepted++;
            }
        }
    }
    scanf("%d", &t);
    printf("%.0lf", double(Accepted) / (double(t) / double(60)));
    return 0;
}