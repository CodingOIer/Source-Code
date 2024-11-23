#include <cstdio>
constexpr int MaxN = 2e1 + 5;
int n;
int w, g, h;
bool rm[MaxN][MaxN][MaxN];
int main()
{
    scanf("%d%d%d", &w, &g, &h);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int sx, sy, sz, ex, ey, ez;
        scanf("%d%d%d%d%d%d", &sx, &sy, &sz, &ex, &ey, &ez);
        for (int x = sx; x <= ex; x++)
        {
            for (int y = sy; y <= ey; y++)
            {
                for (int z = sz; z <= ez; z++)
                {
                    rm[x][y][z] = true;
                }
            }
        }
    }
    int answer = 0;
    for (int x = 1; x <= w; x++)
    {
        for (int y = 1; y <= g; y++)
        {
            for (int z = 1; z <= h; z++)
            {
                answer += !rm[x][y][z] ? 1 : 0;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
