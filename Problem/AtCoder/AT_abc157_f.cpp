#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
int n, k;
double ansx, ansy, answ, t;
struct node
{
    double x, y, c;
} p[65];
double ans[65];
double calc(double x, double y)
{
    for (int i = 1; i <= n; i++)
        ans[i] = (double)p[i].c * sqrt(((x - p[i].x) * (x - p[i].x) + (y - p[i].y) * (y - p[i].y)));
    sort(ans + 1, ans + n + 1);
    return ans[k];
}
void sa()
{
    t = 1949;
    while (t > 1e-14)
    {
        double nx = t * (rand() * 2 - RAND_MAX) + ansx;
        double ny = t * (rand() * 2 - RAND_MAX) + ansy;
        double nw = calc(nx, ny);
        double delta = nw - answ;
        if (delta < 0)
            ansx = nx, answ = nw, ansy = ny;
        else if (exp(-delta / t) * RAND_MAX > rand())
            ansx = nx, ansy = ny, answ = nw;
        t *= 0.999;
    }
}
int main()
{
    srand(rand());
    answ = INT_MAX;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].c;
    while ((double)clock() / CLOCKS_PER_SEC < 1.98)
        sa();
    cout << fixed << setprecision(6) << answ << endl;
    return 0;
}