#include <cstdio>
#include <ctime>
#include <queue>
#include <random>
const int MaxN = 2e5 + 5;
class str
{
  public:
    int x, y;
    int to_x, to_y;
};
int ok;
int n, m;
int change;
int people_x[MaxN];
int people_y[MaxN];
str input[MaxN];
bool use[MaxN];
bool know[MaxN];
std::mt19937 rnd;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        str t;
        scanf("%d%d%d%d", &t.x, &t.y, &t.to_x, &t.to_y);
        input[i] = t;
    }
    ok = 1;
    know[1] = true;
    people_x[1] = 0;
    people_y[1] = 0;
    for (; ok != n && (clock() / CLOCKS_PER_SEC <= 2.3);)
    {
    make_rand:;
        unsigned int x;
        x = rnd() % m + 1;
        if (use[x])
        {
            change++;
            goto make_rand;
        }
        str t;
        t = input[x];
        use[x] = true;
        if (know[t.x])
        {
            change = 0;
            know[t.y] = true;
            people_x[t.y] = people_x[t.x] + t.to_x;
            people_y[t.y] = people_y[t.x] + t.to_y;
            ok++;
        }
        else if (know[t.y])
        {
            change = 0;
            know[t.x] = true;
            people_x[t.x] = people_x[t.y] - t.to_x;
            people_y[t.x] = people_y[t.y] - t.to_y;
            ok++;
        }
        else
        {
            use[x] = false;
            change++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (know[i])
        {
            printf("%d %d\n", people_x[i], people_y[i]);
        }
        else
        {
            printf("undecidable\n");
        }
    }
    return 0;
}