#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#define debug printf("Debug\n")
typedef long long ll;
int n;
int op, x;
std::priority_queue<int> p;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            p.push(-x);
        }
        else if (op == 2)
        {
            printf("%d\n", -p.top());
        }
        else if (op == 3)
        {
            p.pop();
        }
    }
    return 0;
}