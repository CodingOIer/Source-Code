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
    node *p = new node;
    p->len = last->len + 1;
    last = p;
    for (; cur != nullptr && cur->to[c] == 0; cur = cur->fa)
    {
        cur->to[c] = p;
    }
    if (cur == nullptr)
    {
        p->fa = root;
        return;
    }
    node *t = cur->to[c];
    node *ct = new node;
    (*ct) = (*t);
    ct->len = cur->len + 1;
    p->fa = t->fa = ct;
    for (; cur != nullptr && cur->to[c] == t; cur = cur->fa)
    {
        cur->to[c] = ct;
    }
}
int main()
{
    root = last = new node();
    return 0;
}