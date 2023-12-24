#include <cstdio>
#include <cstdlib>
const int MaxN = 7;
class block
{
  public:
    int h, w;
    int block[MaxN][MaxN];
};
int n;
int sum[MaxN][MaxN];
char s[MaxN][MaxN][MaxN];
block p[5];
bool haveH(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][y][i] == '#')
        {
            return true;
        }
    }
    return false;
}
bool haveW(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[x][i][y] == '#')
        {
            return true;
        }
    }
    return false;
}
void rotate(int id)
{
    block t;
    t.h = p[id].w;
    t.w = p[id].h;
    for (int i = 1; i <= p[id].h; i++)
    {
        for (int j = 1; j <= p[id].w; j++)
        {
            t.block[j][p[id].h - i + 1] = p[id].block[i][j];
        }
    }
    p[id] = t;
}
void check()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sum[i][j] != 1)
            {
                return;
            }
        }
    }
    printf("Yes\n");
    exit(0);
}
void dfs(int id)
{
    if (id == 4)
    {
        check();
    }
    else
    {
        for (int r = 1; r <= 4; r++)
        {
            for (int x = 0; x <= n - p[id].h; x++)
            {
                for (int y = 0; y <= n - p[id].w; y++)
                {
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] += p[id].block[i][j];
                        }
                    }
                    dfs(id + 1);
                    for (int i = 1; i <= p[id].h; i++)
                    {
                        for (int j = 1; j <= p[id].w; j++)
                        {
                            sum[i + x][j + y] -= p[id].block[i][j];
                        }
                    }
                }
            }
            rotate(id);
        }
    }
}
int main()
{
    n = 4;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%s", s[i][j] + 1);
        }
    }
    for (int id = 1; id <= 3; id++)
    {
        int start_h;
        start_h = 1;
        for (; !haveH(id, start_h);)
        {
            start_h++;
        }
        int end_h;
        end_h = n;
        for (; !haveH(id, end_h);)
        {
            end_h--;
        }
        int start_w;
        start_w = 1;
        for (; !haveW(id, start_w);)
        {
            start_w++;
        }
        int end_w;
        end_w = n;
        for (; !haveW(id, end_w);)
        {
            end_w--;
        }
        p[id].h = end_h - start_h + 1;
        p[id].w = end_w - start_w + 1;
        for (int i = start_h; i <= end_h; i++)
        {
            for (int j = start_w; j <= end_w; j++)
            {
                p[id].block[i - start_h + 1][j - start_w + 1] = (s[id][i][j] == '#') ? 1 : 0;
            }
        }
    }
    dfs(1);
    printf("No\n");
    return 0;
}