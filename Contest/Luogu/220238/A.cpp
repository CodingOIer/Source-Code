#include <cassert>
#include <cstdio>
#include <cstdlib>
void solve1()
{
    double ac;
    scanf("%lf", &ac);
    if (ac >= 97)
    {
        printf("S\n");
    }
    else if (ac >= 95)
    {
        printf("A\n");
    }
    else if (ac >= 90)
    {
        printf("B\n");
    }
    else if (ac >= 85)
    {
        printf("C\n");
    }
    else if (ac >= 80)
    {
        printf("D\n");
    }
    else
    {
        printf("F\n");
    }
}
void solve2()
{
    int day = 0;
    scanf("%d", &day);
    if (day == 20221029)
    {
        printf("280\n");
    }
    else if (day == 2023021)
    {
        printf("250\n");
    }
    else if (day == 20231118)
    {
        printf("275\n");
    }
    else if (day == 20240201)
    {
        printf("144\n");
    }
    else if (day == 20240518)
    {
        printf("115\n");
    }
    else if (day == 20240718)
    {
        printf("199\n");
    }
    else if (day == 20240720)
    {
        printf("140\n");
    }
    else if (day == 20241026)
    {
        printf("376\n");
    }
    else if (day == 20241130)
    {
        printf("320\n");
    }
    else
    {
        printf("-1\n");
    }
}
void solve3()
{
    int tid;
    scanf("%d", &tid);
    if (tid == 673208)
    {
        printf("0 0 0 0 5 9 11\n");
    }
    if (tid == 672011)
    {
        printf("0 0 0 0 1 8 11\n");
    }
    if (tid == 669627)
    {
        printf("0 0 0 0 0 3 12\n");
    }
    if (tid == 667834)
    {
        printf("0 0 0 3 4 17 6\n");
    }
    if (tid == 659428)
    {
        printf("0 2 8 9 2 0 0\n");
    }
    if (tid == 654700)
    {
        printf("0 0 0 0 0 19 0\n");
    }
    if (tid == 653408)
    {
        printf("0 9 2 0 0 0 0\n");
    }
    if (tid == 643317)
    {
        printf("0 0 0 0 0 5 7\n");
    }
    if (tid == 643309)
    {
        printf("0 0 0 2 2 17 27\n");
    }
    if (tid == 607065)
    {
        printf("11 6 0 0 0 0 0\n");
    }
    if (tid == 522623)
    {
        printf("0 1 1 1 2 0 0\n");
    }
    if (tid == 510440)
    {
        printf("0 0 0 1 1 1 0\n");
    }
    if (tid == 506642)
    {
        printf("0 0 0 0 5 4 1\n");
    }
    if (tid == 504298)
    {
        printf("0 0 0 0 13 15 1\n");
    }
    if (tid == 452944)
    {
        printf("0 0 0 0 0 12 6\n");
    }
    if (tid == 446735)
    {
        printf("0 0 0 2 13 9 0\n");
    }
    if (tid == 442843)
    {
        printf("0 0 0 0 2 7 1\n");
    }
    if (tid == 440130)
    {
        printf("0 0 0 0 1 7 5\n");
    }
    if (tid == 439883)
    {
        printf("0 0 0 0 1 4 6\n");
    }
    if (tid == 439196)
    {
        printf("0 0 0 0 0 3 12\n");
    }
    if (tid == 437466)
    {
        printf("0 0 0 0 0 1 4\n");
    }
    if (tid == 437017)
    {
        printf("0 0 1 0 0 3 2\n");
    }
    if (tid == 436539)
    {
        printf("0 0 0 0 0 6 44\n");
    }
    if (tid == 436300)
    {
        printf("0 0 1 1 1 6 12\n");
    }
    if (tid == 436262)
    {
        printf("0 0 0 0 0 11 7\n");
    }
    if (tid == 436185)
    {
        printf("0 0 0 0 0 10 6\n");
    }
}
void solve4()
{
    int level;
    scanf("%d", &level);
    int answer[] = {0, 5, 20, 50, 150, 400, 1000, 2000, 4000, 8000, 15000, 35000, 75000, 100000};
    printf("%d\n", answer[level]);
}
constexpr int MaxN = 1e2 + 5;
int n, m;
int p[MaxN];
int last[MaxN];
void solve5()
{
    scanf("%d%d", &n, &m);
    int ouX = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] == n)
        {
            ouX = ouX == 0 ? i : ouX;
        }
        else
        {
            if (last[p[i]] == 0)
            {
                last[p[i]] = i;
            }
            else
            {
                last[p[i]] = m + 1;
            }
        }
    }
    if (ouX == 0)
    {
        printf("0\n");
        return;
    }
    int answer = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (ouX <= last[i])
        {
            answer++;
        }
    }
    printf("%d\n", answer);
}
int main()
{
    int id;
    scanf("%d", &id);
    if (id == 1)
    {
        solve1();
    }
    else if (id == 2)
    {
        solve2();
    }
    else if (id == 3)
    {
        solve3();
    }
    else if (id == 4)
    {
        solve4();
    }
    else if (id == 5)
    {
        solve5();
    }
    return 0;
}
