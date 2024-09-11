#include <cstdio>
#include <map>
#define max(a, b) (a > b ? a : b)
const int MaxN = 2e5 + 5;
int n;
int num;
int answer;
char last;
char s[MaxN];
std::map<char, int> map;
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    last = '\0';
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == last)
        {
            num++;
        }
        else
        {
            num = 1;
            last = s[i];
        }
        map[s[i]] = max(map[s[i]], num);
    }
    for (int i = 0; i < 26; i++)
    {
        answer += map['a' + i];
    }
    printf("%d\n", answer);
    return 0;
}