#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e6 + 5;
int n, m;
int answer;
int fail[MaxN];
char s[MaxN];
char t[MaxN];
void build()
{
    fail[0] = 0;
    fail[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        int cp = fail[i - 1];
        for (; t[cp + 1] != t[i] && cp != 0;)
        {
            cp = fail[cp];
        }
        if (t[cp + 1] == t[i])
        {
            cp++;
        }
        fail[i] = cp;
    }
}
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    build();
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        for (; s[i] != t[cur + 1] && cur != 0;)
        {
            cur = fail[cur];
        }
        if (s[i] == t[cur + 1])
        {
            cur++;
        }
        answer += cur == m ? 1 : 0;
    }
    printf("%d\n", answer);
    return 0;
}