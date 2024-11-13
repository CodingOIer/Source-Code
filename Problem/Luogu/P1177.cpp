#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define debug printf("Debug\n")
typedef long long ll;
const int MaxN = 1e5 + 5;
int n;
int p[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}