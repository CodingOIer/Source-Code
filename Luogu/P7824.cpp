#include <cstdio>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int n, k;
std::vector<int> need[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    int rk = k;
    for (int i = 0; i < n; i++)
    {
        int x = i;
        int id = 0;
        for (; x != 0;)
        {
            if (x & 1)
            {
                need[id].push_back(i + 1);
            }
            x /= 2;
            id++;
        }
    }
    k = 0;
    for (int i = 0;; i++)
    {
        if (need[i].size() == 0)
        {
            break;
        }
        k++;
        printf("1 %zu", need[i].size());
        for (auto x : need[i])
        {
            printf(" %d", x);
        }
        printf("\n");
        printf("1 %zu", need[i].size());
        for (auto x : need[i])
        {
            printf(" %d", x);
        }
        printf("\n");
        printf("1 %zu", need[i].size());
        for (auto x : need[i])
        {
            printf(" %d", x);
        }
        printf("\n");
    }
    printf("2\n");
    fflush(stdout);
    int answer = 0;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if ((a + b + c) / 2)
        {
            answer += (1 << i);
        }
    }
    printf("%d\n", answer + 1);
    return 0;
}