#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
        else if (s[i] == '_')
        {
            s[i] = '-';
        }
    }
    printf("solution-%s", s);
    return 0;
}