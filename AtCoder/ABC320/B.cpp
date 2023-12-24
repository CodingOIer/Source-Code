#include <algorithm>
#include <cstdio>
#include <cstring>
const int MaxN = 1e2 + 5;
int n;
int answer;
char s[MaxN];
int main()
{
    scanf("%s", (s + 1));
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            bool flag;
            flag = true;
            for (int l = i, r = j; l < r; l++, r--)
            {
                if (s[l] != s[r])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                answer = std::max(answer, j - i + 1);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}