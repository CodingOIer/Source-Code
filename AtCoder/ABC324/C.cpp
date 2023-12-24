#include <cstdio>
#include <cstring>
const int MaxN = 5e5 + 5;
int n;
int cnt;
int len_b;
int len_n;
int same[MaxN];
char k[MaxN];
char now[MaxN];
char before[MaxN];
bool change(char a[], char b[])
{
    int center = 0;
    for (; a[center] == b[center];)
    {
        center++;
    }
    int len_1, len_2;
    len_1 = strlen(a);
    len_2 = strlen(b);
    for (int i = len_1; i > center; i--)
    {
        if (a[i] != b[i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d %s", &n, now);
    len_n = strlen(now);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", before);
        len_b = strlen(before);
        if (strcmp(before, now) == 0) // 1
        {
            cnt++;
            same[cnt] = i;
        }
        else
        {
            if (len_b == len_n) // 4
            {
                int different = 0;
                for (int w = 0; w < len_b; w++)
                {
                    different += before[w] != now[w] ? 1 : 0;
                }
                if (different == 1)
                {
                    cnt++;
                    same[cnt] = i;
                }
            }
            else if (len_n + 1 == len_b && change(before, now) || len_n == len_b + 1 && change(now, before))
            {
                cnt++;
                same[cnt] = i;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d ", same[i]);
    }
    printf("\n");
    return 0;
}