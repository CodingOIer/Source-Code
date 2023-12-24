#include <cstdio>
const int MaxN = 1e2 + 5;
int n, m;
int answer[5][5] = {{3, 2}, {1, 0}};
char s[MaxN];
char t[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    bool front, end;
    front = true;
    end = true;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != t[i])
        {
            front = false;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i] != t[i + (m - n)])
        {
            end = false;
        }
    }
    printf("%d\n", answer[front][end]);
    return 0;
}