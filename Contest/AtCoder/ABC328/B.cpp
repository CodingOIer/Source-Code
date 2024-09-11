#include <cstdio>
int n;
int x;
int answer;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        bool check = true;
        for (; tmp >= 10;)
        {
            if (tmp % 10 != tmp / 10)
            {
                check = false;
            }
            tmp /= 10;
        }
        scanf("%d", &x);
        if (check)
        {
            int now = i % 10;
            for (; now <= x;)
            {
                answer++;
                now = now * 10 + i % 10;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}