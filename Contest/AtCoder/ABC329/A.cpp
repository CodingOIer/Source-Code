#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c ", s[i]);
    }
    return 0;
}