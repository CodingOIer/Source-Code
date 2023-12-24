#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    for (int i = 1; i < 16; i += 2)
    {
        if (s[i] == '1')
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}