#include <utility>
#include <vector>
int Query(int x);

void init()
{
}

int getMid(int l, int r, int n)
{
    if (l == 1 && r == n)
    {
        return n / 3;
    }
    return (l + r) / 2;
}

int want(std::vector<int> &vis, int x)
{
    return vis[x] == 2 ? vis[x] = Query(x) : vis[x];
}

std::pair<int, int> Guess(int n, int c)
{
    std::vector<int> vis(n + 5, 2);
    int ll, lr;
    int les;
    int rl, rr;
    int res;
    ll = rl = 1;
    lr = rr = n;
    les = -1;
    res = -1;
    int mid = getMid(ll, lr, n);
    int r = want(vis, mid);
    if (r == 0)
    {
        les = mid;
        lr = mid - 1;
    }
    else if (r == 1)
    {
        lr = mid - 1;
    }
    else if (r == -1)
    {
        ll = mid + 1;
    }
    for (; ll <= lr;)
    {
        int mid = getMid(ll, lr, n);
        int r = want(vis, mid);
        if (r == 0)
        {
            les = mid;
            lr = mid - 1;
        }
        else if (r == 1)
        {
            lr = mid - 1;
        }
        else if (r == -1)
        {
            ll = mid + 1;
        }
    }
    r = want(vis, mid);
    if (r == 0)
    {
        res = mid;
        rl = mid + 1;
    }
    else if (r == -1)
    {
        rl = mid + 1;
    }
    else if (r == 1)
    {
        rr = mid - 1;
    }
    for (; rl <= rr;)
    {
        int mid = getMid(rl, rr, n);
        int r = want(vis, mid);
        if (r == 0)
        {
            res = mid;
            rl = mid + 1;
        }
        else if (r == -1)
        {
            rl = mid + 1;
        }
        else if (r == 1)
        {
            rr = mid - 1;
        }
    }
    return {les, res};
}
