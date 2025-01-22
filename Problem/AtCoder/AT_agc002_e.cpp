#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n, [](const int &x, const int &y) -> bool { return x > y; });
    int maxBlock = 1;
    for (; maxBlock <= n; maxBlock++)
    {
        if (!(maxBlock <= p[maxBlock]))
        {
            maxBlock--;
            break;
        }
    }
    maxBlock = std::min(n, maxBlock);
    int maxLength = 1;
    for (; maxBlock + maxLength <= n; maxLength++)
    {
        if (!(maxBlock <= p[maxBlock + maxLength]))
        {
            maxLength--;
            break;
        }
    }
    maxLength = std::min(n - maxBlock, maxLength);
    if ((p[maxBlock] - maxBlock) % 2 == 1 || maxLength % 2 == 1)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}
