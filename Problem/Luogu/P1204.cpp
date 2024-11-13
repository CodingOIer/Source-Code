#include <cstdio>
const int MaxM = 1e6 + 5;
int n;
int l, r;
int last;
int temp;
int first;
int answer1;
int answer2;
int cow[MaxM];
int tree[4 * MaxM];
int lazy[4 * MaxM];
void push_down(int s, int t, int k)
{
    if (lazy[k] != 0)
    {
        int mid = (s + t) / 2;
        tree[2 * k] += (mid - s + 1) * lazy[k];
        tree[2 * k + 1] += (t - mid) * lazy[k];
        lazy[2 * k] += lazy[k];
        lazy[2 * k + 1] += lazy[k];
        lazy[k] = 0;
    }
}
void change(int s, int t, int l, int r, int k, int c)
{
    if (l <= s && t <= r)
    {
        tree[k] += (t - s + 1) * c;
        lazy[k] += c;
        return;
    }
    push_down(s, t, k);
    int mid = (s + t) / 2;
    if (l <= mid)
    {
        change(s, mid, l, r, 2 * k, c);
    }
    if (r >= mid + 1)
    {
        change(mid + 1, t, l, r, 2 * k + 1, c);
    }
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}
int sum(int s, int t, int l, int r, int k)
{
    if (l <= s && t <= r)
    {
        return tree[k];
    }
    push_down(s, t, k);
    int mid = (s + t) / 2;
    int res = 0;
    if (l <= mid)
    {
        res += sum(s, mid, l, r, 2 * k);
    }
    if (r >= mid + 1)
    {
        res += sum(mid + 1, t, l, r, 2 * k + 1);
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l, &r);
        change(0, 1e6, l, r, 1, 1);
    }
    first = -1;
    for (int i = 0; i <= 1e6; i++)
    {
        cow[i] = sum(0, 1e6, i, i, 1) != 0 ? 1 : 0;
        last = cow[i] == 1 ? i : last;
        first = first == -1 && cow[i] == 1 ? i : first;
    }
    for (int i = first; i <= last; i++)
    {
        if (cow[i] == 0)
        {
            break;
        }
        answer1++;
    }
    for (int i = first; i <= last; i++)
    {
        if (cow[i] == 0)
        {
            temp++;
        }
        answer2 = temp > answer2 ? temp : answer2;
        if (cow[i] != 0)
        {
            temp = 0;
        }
    }
    printf("%d %d\n", answer1 - 1, answer2 + 1);
    return 0;
}