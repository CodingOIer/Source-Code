#include <algorithm>
#include <cstdio>
#include <utility>
int n;
int p[15];
int main()
{
    n = 4;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    int cnt = 0;
    int last = -1;
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (last != p[i])
        {
            last = p[i];
            cnt++;
        }
        if (cnt > 2)
        {
            printf("No\n");
            return 0;
        }
        if (cnt == 1)
        {
            cnt1++;
        }
        if (cnt == 2)
        {
            cnt2++;
        }
    }
    if (cnt2 < cnt1)
    {
        std::swap(cnt1, cnt2);
    }
    printf("%s\n", (cnt1 == 2 && cnt2 == 2) || (cnt1 == 1 && cnt2 == 3) ? "Yes" : "No");
    return 0;
}
