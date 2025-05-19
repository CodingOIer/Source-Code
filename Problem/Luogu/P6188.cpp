#include <algorithm>
#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int answerA, answerB, answerC;
    answerA = answerB = answerC = -1;
    for (int a = 0; 7 * a <= n; a++)
    {
        for (int b = 0; 7 * a + 4 * b <= n; b++)
        {
            int c = n - 7 * a - 4 * b;
            if (c % 3 != 0)
            {
                continue;
            }
            c /= 3;
            if (std::min({a, b, c}) > std::min({answerA, answerB, answerC}) ||
                (std::min({a, b, c}) == std::min({answerA, answerB, answerC}) &&
                 a + b + c > answerA + answerB + answerC))
            {
                answerA = a;
                answerB = b;
                answerC = c;
            }
        }
    }
    if (answerA == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d %d\n", answerA, answerB, answerC);
    }
    return 0;
}