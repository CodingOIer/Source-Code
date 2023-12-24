#include <algorithm>
#include <cstdio>
const int MaxN = 3e5 + 5;
int n, m;
int answer;
int p[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int now = p[i];
        int res;
        res = i;
        int l, r;
        l = i;
        r = n;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            if (p[mid] < now + m)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        answer = answer > (res - i + 1) ? answer : (res - i + 1);
    }
    printf("%d\n", answer);
    return 0;
}