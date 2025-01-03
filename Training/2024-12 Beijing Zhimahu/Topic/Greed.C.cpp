#include <cstdio>
#include <queue>
#include <tuple>
constexpr int MaxN = 3e5 + 5;
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
int n, k;
int p[MaxN];
node *head, *tail;
std::priority_queue<std::tuple<int, node *>> queue;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    head = new node;
    tail = new node;
    node *temp = new node;
    temp->use = true;
    head->left = temp;
    temp->right = head;
    temp = new node;
    temp->use = true;
    tail->right = temp;
    temp->left = tail;
    head->right = tail;
    tail->left = head;
    for (int i = 1; i <= n; i++)
    {
        node *cur = new node;
        cur->left = tail->left;
        cur->right = tail;
        tail->left->right = cur;
        tail->left = cur;
        cur->x = p[i];
        queue.push({p[i], cur});
    }
    long long answer = 0;
    for (int i = 1; i <= k; i++)
    {
        auto [x, cur] = queue.top();
        queue.pop();
        if (cur->use)
        {
            i--;
            continue;
        }
        if (x <= 0)
        {
            break;
        }
        answer += x;
        if (!cur->left->use && !cur->right->use)
        {
            cur->x = cur->left->x + cur->right->x - cur->x;
            cur->left->use = true;
            cur->right->use = true;
            cur->left->left->right = cur;
            cur->right->right->left = cur;
            cur->left = cur->left->left;
            cur->right = cur->right->right;
            queue.push({cur->x, cur});
        }
    }
    printf("%lld\n", answer);
    return 0;
}
