#include <algorithm>
#include <cstdio>
#include <cstring>
const int MaxN = 15;
const int MaxM = 1e2 + 5;
int n, m;
int answer;
int number[MaxN][MaxM];
char s[MaxM];
int main()
{
    n = 3;
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            number[i][j] = s[j] - '0';
        }
    }
    answer = 0x3f3f3f3f;
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    for (int x = 0; x <= 9; x++)
    {
        bool fa, fb, fc;
        fa = false;
        fb = false;
        fc = false;
        for (int j = 0; j < 5 * m; j++)
        {
            if (false)
            {
            }
            else if (number[3][j % m + 1] == x && !fc)
            {
                fc = true;
            }
            else if (number[2][j % m + 1] == x && !fb)
            {
                fb = true;
            }
            else if (number[1][j % m + 1] == x && !fa)
            {
                fa = true;
            }
            if (fa && fb && fc)
            {
                answer = std::min(answer, j);
                break;
            }
        }
    }
    printf("%d\n", answer == 0x3f3f3f3f ? -1 : answer);
    return 0;
}