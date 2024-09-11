#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
const int MaxN = 5e5 + 5;
int n;
int len_t;
int len_i;
int len_j;
long long answer;
std::string t;
std::string s[MaxN];
int main()
{
    scanf("%d", &n);
    std::cin >> t;
    len_t = t.size();
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            len_i = s[i].size();
            len_j = s[j].size();
            if (len_i + len_j < len_t)
            {
                continue;
            }
            else
            {
                int x = -1;
                std::string with = s[i] + s[j];
                int len_w = with.size();
                for (int y = 0; y < len_w; y++)
                {
                    if (with[y] == t[x + 1])
                    {
                        x++;
                    }
                    if (x == len_t - 1)
                    {
                        break;
                    }
                }
                if (x == len_t - 1)
                {
                    answer++;
                }
            }
        }
    }
    printf("%lld\n", answer);
    return 0;
}