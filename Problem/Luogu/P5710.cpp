#include <cstdio>
int x;
int main()
{
    scanf("%d", &x);
    printf("%d %d %d %d\n", (x % 2 == 0) && (5 <= x && x <= 12), (x % 2 == 0) || (5 <= x && x <= 12),
           (x % 2 == 0) ^ (5 <= x && x <= 12), !((x % 2 == 0) || (5 <= x && x <= 12)));
    return 0;
}