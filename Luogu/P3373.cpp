constexpr int MaxN = 1e5 + 5;
constexpr long long Mod = 571373;
int n;
int p[MaxN];
long long tree[MaxN * 4];
long long lazy1[MaxN * 4];
long long lazy2[MaxN * 4];
void build(int c, int s, int t)
{
    lazy2[c] = 1;
    if (s == t)
    {
        tree[c] = p[s];
        return;
    }
}
inline void downstream(int c, int s, int t)
{
    if (lazy1[c] != 1)
    {
        tree[c * 2] *= lazy1[c];
        tree[c * 2] %= Mod;
        lazy1[c * 2] *= lazy1[c];
        lazy1[c * 2] %= Mod;
        lazy2[c * 2] *= lazy1[c];
        lazy1[c * 2] %= Mod;
        tree[c * 2 + 1] *= lazy1[c];
        tree[c * 2 + 1] %= Mod;
        lazy1[c * 2 + 1] *= lazy1[c];
        lazy1[c * 2 + 1] %= Mod;
        lazy2[c * 2 + 1] *= lazy1[c];
        lazy1[c * 2 + 1] %= Mod;
        lazy1[c] = 1;
    }
    if (lazy2[c] != 0)
    {
        int mid = (s + t) / 2;
        tree[c * 2] += lazy2[c] * (mid - s + 1);
        tree[c * 2 + 1] += lazy2[c] * (t - mid);
        lazy2[c * 2] += lazy2[c];
        lazy2[c * 2 + 1] += lazy2[c];
        lazy2[c] = 0;
    }
}
void change1(int c, int s, int t, int l, int r, long long val)
{
    if (l <= s && t <= r)
    {
        tree[c] *= val;
        
    }
}
int main()
{
    return 0;
}