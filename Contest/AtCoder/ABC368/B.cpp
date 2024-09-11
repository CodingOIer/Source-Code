#include <algorithm>
#include <cstdio>
#include <queue>
int n;
int p[105];
std::priority_queue<int> queue;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        queue.push(p[i]);
    }
    int answer = 0;
    for (; queue.size() > 1;)
    {
        int x = queue.top();
        queue.pop();
        int y = queue.top();
        queue.pop();
        x--;
        y--;
        if (x > 0)
        {
            queue.push(x);
        }
        if (y > 0)
        {
            queue.push(y);
        }
        answer++;
    }
    printf("%d", answer);
    return 0;
}