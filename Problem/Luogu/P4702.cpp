#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    printf("%s\n", sum % 2 == 0 ? "Bob" : "Alice");
    return 0;
}