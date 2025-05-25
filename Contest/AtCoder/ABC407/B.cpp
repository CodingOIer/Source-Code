#include <cstdio>
#include <cstdlib>
int x, y;
int answer;
int main()
{
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j >= x || std::abs(i - j) >= y)
            {
                answer++;
            }
        }
    }
    printf("%.15lf\n", 1.0 * answer / 36);
    return 0;
}