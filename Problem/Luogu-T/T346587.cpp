/**
 * @file Luogu\T346587.cpp
 * @author CodingOIer (redefinition0726@163.com)
 * @brief Luogu
 * @version 1.0
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <algorithm>
#include <cstdio>
#include <set>
constexpr int MaxN = 6e6 + 5;
class node
{
  public:
    int x;
    int id;
    node *left, *right;
    node()
    {
        x = 0;
        id = 0;
        left = nullptr;
        right = nullptr;
    }
};
int n, q;
node *link[MaxN];
node *head, *tail;
std::multiset<int> set;
void merge(node *left, node *middle, node *right)
{
    left->right = right;
    right->left = left;
    middle->left = left;
    middle->right = right;
}
int main()
{
    scanf("%d", &n);
    head = new node();
    tail = new node();
    head->right = tail;
    tail->left = head;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        set.insert(x);
        node *temp = new node();
        temp->x = x;
        temp->id = i;
        merge(tail->left, temp, tail);
        link[i] = temp;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 2)
        {
            printf("%d\n", set.rbegin());
        }
        else if (op == 1)
        {
        }
    }
    return 0;
}