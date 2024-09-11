#include <cstdio>
const int MaxN = 1e3 + 5;
int n;
int use_com;
int max_com;
int use_flag;
int max_flag;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &max_com);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            use_com = 0;
            use_flag = 0;
        }
        else if (s[i] == '1')
        {
            if (use_com < max_com)
            {
                use_com++;
            }
            else if (use_flag < max_flag)
            {
                use_flag++;
            }
            else
            {
                use_flag++;
                max_flag++;
            }
        }
        else if (s[i] == '2')
        {
            if (use_flag < max_flag)
            {
                use_flag++;
            }
            else
            {
                use_flag++;
                max_flag++;
            }
        }
    }
    printf("%d\n", max_flag);
    return 0;
}