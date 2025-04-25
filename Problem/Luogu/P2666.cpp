#include <cstdio>
int n;
int answer;
void dfs(int x, int w)
{
    if (x == 5 && w == 0)
    {
        answer++;
    }
    if (x == 5)
    {
        return;
    }
    for (int i = 0; i * i <= w; i++)
    {
        dfs(x + 1, w - i * i);
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1, n);
    printf("%d\n", answer);
    return 0;
}