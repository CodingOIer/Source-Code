#include <algorithm>
#include <cstdio>
int p[15];
int main()
{
    scanf("%d%d%d%d", &p[1], &p[2], &p[3], &p[4]);
    std::sort(p + 1, p + 5);
    printf("%d\n", (p[1] == p[2]) + (p[3] == p[4]) == 0 ? p[2] == p[3] : (p[1] == p[2]) + (p[3] == p[4]));
    return 0;
}