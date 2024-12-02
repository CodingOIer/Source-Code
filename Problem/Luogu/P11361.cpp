#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e5 + 5;
int n;
int cntS[MaxN][2];
int cntT[MaxN][2];
int groupS[MaxN];
int groupT[MaxN];
char s[MaxN];
char t[MaxN];
char allowS[MaxN];
char allowT[MaxN];
void solve()
{
    memset(cntS, 0, sizeof(cntS));
    memset(cntT, 0, sizeof(cntT));
    scanf("%d", &n);
    scanf(" %s", s + 1);
    scanf(" %s", t + 1);
    scanf(" %s", allowS + 1);
    scanf(" %s", allowT + 1);
    int indexS, indexT;
    indexS = indexT = 0;
    for (int i = 1; i <= n; i++)
    {
        if (allowS[i] == '0' || (allowS[i] == '1' && allowS[i - 1] != '1'))
        {
            groupS[i] = ++indexS;
        }
        else
        {
            groupS[i] = groupS[i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (allowT[i] == '0' || (allowT[i] == '1' && allowT[i - 1] != '1'))
        {
            groupT[i] = ++indexT;
        }
        else
        {
            groupT[i] = groupT[i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cntS[groupS[i]][s[i] ^ 48]++;
        cntT[groupT[i]][t[i] ^ 48]++;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cntS[groupS[i]][0] >= 1 && cntT[groupT[i]][0] >= 1)
        {
            cntS[groupS[i]][0]--;
            cntT[groupT[i]][0]--;
            answer++;
        }
        else if (cntS[groupS[i]][1] >= 1 && cntT[groupT[i]][1] >= 1)
        {
            cntS[groupS[i]][1]--;
            cntT[groupT[i]][1]--;
            answer++;
        }
    }
    printf("%d\n", answer);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
