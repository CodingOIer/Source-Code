#include <cstdio>
int main()
{
    int l, r;
    l = 1;
    r = 1e9;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        printf("%d\n", mid);
        fflush(stdout);
        int re;
        scanf("%d", &re);
        if (re == 0)
        {
            break;
        }
        else if (re > 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}