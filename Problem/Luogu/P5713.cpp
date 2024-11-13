#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    printf("%s\n", n <= 5 ? "Local" : "Luogu");
    return 0;
}