#include <cstdio>
int t;
int main()
{
    scanf("%d", &t);
    if (t == 1)
    {
        printf(R"(
1
-1)");
    }
    else if (t == 2)
    {
        printf("%lld\n", (long long)(1e11 + 73));
    }
    else if (t == 3)
    {
        printf(R"(
2
1000000000 1000000000)");
    }
    return 0;
}