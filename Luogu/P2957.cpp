#include <algorithm>
#include <cstdio>
#include <cstring>
const int MaxN = 8e1 + 5;
int n, m;
int answer;
char s[MaxN];
char t[MaxN];
bool check(const int &start_s, const int &end_s)
{
}
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    if (strlen(s + 1) < strlen(t + 1))
    {
        char k[MaxN];
        strcpy(k + 1, s + 1);
        strcpy(s + 1, t + 1);
        strcpy(t + 1, k + 1);
    }
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m; i++)
    {
    }
    return 0;
}
