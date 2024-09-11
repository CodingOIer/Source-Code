#include <cstdio>
#include <cstring>

const int MaxN = 1e5 + 5;

int n, m;

int x;

int AC;
int WA;

int problem_list[MaxN];

char result[5];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %s", &x, result);

        if (problem_list[x] == -1)
        {
            continue;
        }

        if (result[0] == 'A')
        {
            WA += problem_list[x];
            problem_list[x] = -1;
            AC++;
        }
        else
        {
            problem_list[x]++;
        }
    }

    printf("%d %d\n", AC, WA);

    return 0;
}