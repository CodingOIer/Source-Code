#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n, c;
long long f;
long long leftCost[MaxN];
long long rightCost[MaxN];
std::priority_queue<int> queue;
std::vector<std::tuple<int, int>> v;
int main()
{
    scanf("%d%d%lld", &n, &c, &f);
    for (int i = 1; i <= c; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }
    std::sort(v.begin(), v.end());
    int it = 0;
    long long leftSum = 0;
    for (const auto &[a, b] : v)
    {
        it++;
        queue.push(b);
        leftSum += b;
        for (; int(queue.size()) > n / 2;)
        {
            leftSum -= queue.top();
            queue.pop();
        }
        if (int(queue.size()) < n / 2)
        {
            leftCost[it] = 0x3f3f'3f3f'3f3f'3f3f;
        }
        else
        {
            leftCost[it] = leftSum;
        }
    }
    for (; !queue.empty();)
    {
        queue.pop();
    }
    std::reverse(v.begin(), v.end());
    it = c + 1;
    long long rightSum = 0;
    for (const auto &[a, b] : v)
    {
        it--;
        queue.push(b);
        rightSum += b;
        for (; int(queue.size()) > n / 2;)
        {
            rightSum -= queue.top();
            queue.pop();
        }
        if (int(queue.size()) < n / 2)
        {
            rightCost[it] = 0x3f3f'3f3f'3f3f'3f3f;
        }
        else
        {
            rightCost[it] = rightSum;
        }
    }
    leftCost[0] = leftCost[c + 1] = rightCost[0] = rightCost[c + 1] = 0x3f3f'3f3f'3f3f'3f3f;
    v.push_back({0, 0});
    std::reverse(v.begin(), v.end());
    for (int i = c; i >= 1; i--)
    {
        const auto &[a, c] = v[i];
        if (leftCost[i - 1] + rightCost[i + 1] + c <= f)
        {
            printf("%d\n", a);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
