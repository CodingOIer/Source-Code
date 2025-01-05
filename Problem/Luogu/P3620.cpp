#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
class node
{
  public:
    bool use;
    long long x;
    node *left, *right;
    node()
    {
        x = 0;
        use = false;
        left = right = nullptr;
    }
};
constexpr int MaxN = 1e5 + 5;
int n, k;
int p[MaxN];
std::priority_queue<std::tuple<long long, node *>, std::vector<std::tuple<long long, node *>>, std::greater<>> queue;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    node *head, *tail;
    head = new node;
    tail = new node;
    head->right = tail;
    tail->left = head;
    head->x = 0x3f3f3f3f'3f3f3f3f;
    tail->x = 0x3f3f3f3f'3f3f3f3f;
    node *temp = new node;
    head->left = temp;
    temp->right = head;
    temp->use = true;
    temp = new node;
    tail->right = temp;
    temp->left = tail;
    temp->use = true;
    for (int i = 1; i <= n - 1; i++)
    {
        node *cur = new node;
        cur->x = p[i + 1] - p[i];
        cur->left = tail->left;
        cur->right = tail;
        tail->left->right = cur;
        tail->left = cur;
        queue.push({cur->x, cur});
    }
    long long cost = 0;
    for (int i = 1; i <= k; i++)
    {
        const auto [x, cur] = queue.top();
        queue.pop();
        if (cur->use)
        {
            i--;
            continue;
        }
        cost += x;
        if (!cur->left->use && !cur->right->use)
        {
            cur->x = cur->left->x + cur->right->x - cur->x;
            cur->left->use = true;
            cur->right->use = true;
            cur->left->left->right = cur;
            cur->left = cur->left->left;
            cur->right->right->left = cur;
            cur->right = cur->right->right;
            queue.push({cur->x, cur});
        }
    }
    printf("%lld\n", cost);
    return 0;
}
