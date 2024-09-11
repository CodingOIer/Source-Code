#include <cstdio>
#include <cstring>
#include <map>
#include <string>
const int MaxN = 5e3 + 5;
const int MaxM = 5e4 + 5;
const int MaxL = 2e1 + 5;
int n, k;
char s[MaxM];
char word[MaxL];
std::map<std::string, int> value;
int main()
{
    scanf("%d%d", &n, &k);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%s %d", word, &tmp);
        value[word] = tmp;
    }
    getchar();
    for (int i = 1; i <= k; i++)
    {
        scanf("%[^\n]s", s + 1);
        getchar();
        int len = strlen(s + 1);
        for (int j = 1; j <= len; j++)
        {
            if (s[j] == '{')
            {
                word[0] = '\0';
                j++;
                for (; s[j] != '}'; j++)
                {
                    sprintf(word, "%s%c", word, s[j]);
                }
                printf("%d", value[word]);
            }
            else
            {
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}