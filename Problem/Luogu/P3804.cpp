constexpr int MaxN = 1e6 + 5;
class node
{
  public:
    int len;
    node *fa;
    node *to[26];
    node()
    {
        len = 0;
        fa = nullptr;
        for (int i = 0; i < 26; i++)
        {
            to[i] = nullptr;
        }
    }
};
int n;
char s[MaxN];
node *root;
node *last;
void expand(int c)
{
    node *cur;
    cur = last;
    node *pNew = new node;
    pNew->len = last->len + 1;
    last = pNew;
    for (; cur != nullptr && cur->to[c] == 0; cur = cur->fa)
    {
        cur->to[c] = pNew;
    }
    if (cur == nullptr)
    {
        pNew->fa = root;
        return;
    }
    node *pBefore = cur->to[c];
    if (cur->len + 1 == pBefore->len)
    {
        pNew->fa = pBefore;
        return;
    }
    node *pClone = new node;
    (*pClone) = (*pBefore);
    pClone->len = cur->len + 1;
    pNew->fa = pBefore->fa = pClone;
    for (; cur != nullptr && cur->to[c] == pBefore; cur = cur->fa)
    {
        cur->to[c] = pClone;
    }
}
int main()
{
    root = last = new node();
    return 0;
}