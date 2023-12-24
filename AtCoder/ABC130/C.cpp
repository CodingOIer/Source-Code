#include <bits/stdc++.h>
using namespace std;
int w, h;
int x, y;
int main()
{
    scanf("%d%d%d%d", &w, &h, &x, &y);
    printf("%.6lf %d", double(w) * double(h) / 2, w % 2 == 0 && h % 2 == 0 && w / 2 == x && h / 2 == y ? 1 : 0);
    return 0;
}