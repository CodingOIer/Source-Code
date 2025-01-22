#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <queue>
#include <vector>
int n;
std::vector<int> v;
std::map<int, int> t;
std::priority_queue<int, std::vector<int>, std::greater<>> queue;
int main()
{
    scanf("%d", &n);
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        answer += x;
        v.push_back(x);
        t[x]++;
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::reverse(v.begin(), v.end());
    int prefixCount = 0;
    for (const auto &val : v)
    {
        int getFreely = std::min(t[val], prefixCount - 2 * int(queue.size()));
        std::vector<int> temp;
        for (int i = 1; i <= getFreely; i++)
        {
            temp.push_back(val);
        }
        int tryMax = std::min(t[val], prefixCount) - getFreely;
        for (int i = 1; i <= tryMax; i += 2)
        {
            int x = queue.top();
            queue.pop();
            if (x < val)
            {
                temp.push_back(val);
                if (i <= tryMax - 1)
                {
                    temp.push_back(val);
                }
            }
            else
            {
                temp.push_back(x);
                int more = 2 * val - x;
                if (i <= tryMax - 1 && more > 0)
                {
                    temp.push_back(more);
                }
            }
        }
        for (const auto &tval : temp)
        {
            queue.push(tval);
        }
        prefixCount += t[val];
    }
    for (; !queue.empty();)
    {
        answer -= queue.top();
        queue.pop();
    }
    printf("%lld\n", answer);
    return 0;
}
