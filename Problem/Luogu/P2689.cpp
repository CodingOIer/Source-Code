#include <cstdio>
int t;
int sx, sy;
int ex, ey;
int main()
{
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &ex, &ey);
    scanf("%d", &t);
    int answer = 0;
    for (int i = 1; i <= t; i++)
    {
        scanf(" ");
        char op;
        scanf("%c", &op);
        if (op == 'W' && sx > ex)
        {
            sx--;
            answer++;
        }
        else if (op == 'E' && sx < ex)
        {
            sx++;
            answer++;
        }
        else if (op == 'S' && sy > ey)
        {
            sy--;
            answer++;
        }
        else if (op == 'N' && sy < ey)
        {
            sy++;
            answer++;
        }
    }
    printf("%d\n", sx == ex && sy == ey ? answer : -1);
    return 0;
}