#include <cstdio>
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    int a, b;
    int cnt_a, cnt_b;
    a = 0;
    b = 0;
    cnt_a = 0;
    cnt_b = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            a += i;
            cnt_a++;
        }
        else
        {
            b += i;
            cnt_b++;
        }
    }
    printf("%.1lf %.1lf", double(a) / cnt_a, double(b) / cnt_b);
    return 0;
}