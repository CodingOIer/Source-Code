#include <algorithm>
#include <cstdio>
const int MaxN = 1e2 + 5;
class player
{
  public:
    int x;
    int id;
};
int n;
char s[MaxN][MaxN];
player oier[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        oier[i].id = i;
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == 'o')
            {
                oier[i].x++;
            }
        }
    }
    std::sort(oier + 1, oier + 1 + n, [](player a, player b) { return a.x > b.x || (a.x == b.x && a.id < b.id); });
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", oier[i].id);
    }
    printf("\n");
    return 0;
}
