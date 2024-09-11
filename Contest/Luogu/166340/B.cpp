#include <cstdio>
int cnt[128];
char s[15];
int main()
{
    scanf("%s", s);
    cnt[s[0]]++;
    cnt[s[1]]++;
    cnt[s[2]]++;
    cnt[s[3]]++;
    if (cnt['A'] > 0 && cnt['C'] == 0 && cnt['D'] == 0)
    {
        printf("I'm so happy.\n");
    }
    else if (cnt['D'] == 0)
    {
        printf("This is ok.\n");
    }
    else
    {
        printf("Never give up.\n");
    }
    return 0;
}