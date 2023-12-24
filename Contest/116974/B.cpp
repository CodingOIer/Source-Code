#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (ll i = (a); i >= (b); --i)
#define tell(ans) out(ans), printf("\n");
#define say(ans) out(ans), printf(" ");
#define pb push_back
#define mid (l + r) >> 1
//
//
//
using namespace std;
inline ll read()
{
    ll f = 0, t = 0;
    char c = getchar();
    while (!isdigit(c))
        t |= (c == '-'), c = getchar();
    while (isdigit(c))
        f = (f << 3) + (f << 1) + c - 48, c = getchar();
    return t ? -f : f;
}
inline void out(ll x)
{
    if (x < 0)
        putchar('-');
    if (x > 9)
        out(x / 10);
    putchar('0' + x % 10);
}
const int MX = 1e6 + 10;
int t[MX], s[MX], d[MX];
int vis[MX], have[MX], fx[MX];
int ans = 0;
int top;
int main()
{
    int n = read(), m = read(), k = read();
    top = n;
    FOR(i, 1, n) d[i] = read();
    FOR(i, 1, m) s[i] = read(), vis[s[i]] = 1;
    FOR(i, 1, k) t[i] = read();
    FOR(i, 1, n)
    {
        int j = d[i];
        while (vis[j])
            j++;
        have[j]++;
        d[i] = j;
        ans = max(j, ans);
        FOR(s, 1, k)
        {
            int j = d[i] + t[s];
            while (vis[j])
                j++;
            fx[j]++;
            ans = max(ans, j);
        }
    }
    cout << ans << endl;
    FOR(i, 1, ans) cout << have[i] << " " << fx[i] << endl;
    return 0;
}
