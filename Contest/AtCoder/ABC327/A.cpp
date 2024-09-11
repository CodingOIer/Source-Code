#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
int n;
char s[MaxN];
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' || s[i] == 'b' && s[i + 1] == 'a')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}