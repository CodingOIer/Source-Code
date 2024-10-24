#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define debug printf("Debug\n")
typedef long long ll;
const int MaxN = 1e6 + 5;
int j;
int len_s;
int len_t;
int p[MaxN];
char s[MaxN];
char t[MaxN];
int main()
{
    scanf("%s", (s + 1));
    scanf("%s", (t + 1));
    len_s = strlen(s + 1);
    len_t = strlen(t + 1);
    p[1] = 0;
    for (int i = 2; i <= len_t; i++)
    {
        for (; j >= 1 && t[i] != t[j + 1];)
        {
            j = p[j];
        }
        if (t[i] == t[j + 1])
        {
            j++;
        }
        p[i] = j;
    }
    j = 0;
    for (int i = 1; i <= len_s; i++)
    {
        for (; j >= 1 && s[i] != t[j + 1];)
        {
            j = p[j];
        }
        if (s[i] == t[j + 1])
        {
            j++;
        }
        if (j == len_t)
        {
            printf("%d\n", i - len_t + 1);
            j = p[j];
        }
    }
    for (int i = 1; i <= len_t; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}