#include <cstdio>
#include <vector>
constexpr int MaxN = 1e5 + 5;
int n;
int p[MaxN];
bool vis[MaxN];
std::vector<int> prime;
void init(int limit = 4e2)
{
    for (int i = 2; i <= limit; i++)
    {
        if (vis[i])
        {
            continue;
        }
        prime.push_back(i);
        for (int j = 2 * i; j <= limit; j += i)
        {
            vis[j] = true;
        }
    }
}
int main()
{
    init();
    scanf("%d", &n);
    int answer = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        for (auto y : prime)
        {
            for (; x % y == 0;)
            {
                p[i]++;
                x /= y;
            }
        }
        if (x != 1)
        {
            p[i]++;
        }
        if (p[i] > 1)
        {
            flag = 1;
        }
        answer ^= p[i];
    }
    if ((answer != 0 && flag != 0) || (answer == 0 && flag == 0))
    {
        printf("Anna\n");
    }
    else
    {
        printf("Bruno\n");
    }
    return 0;
}