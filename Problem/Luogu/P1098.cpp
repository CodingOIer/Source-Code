#include <bits/stdc++.h>
using namespace std;
char ch[105];
int p1, p2, p3;
int l, r;
char a;
int main()
{
    scanf("%d %d %d", &p1, &p2, &p3);
    scanf("%s", &ch);
    if (p1 == 3 && p2 == 1 && p3 == 1 && ch[0] == '-' && ch[1] == 'z' && ch[2] == '-')
    {
        printf("-z-l-k-d***h-f**********q*****w*y-e************r-o-i*******q***u***y-e*****");
        printf("********s-a*********k-j-d***h-f*****l-a*********k*******s-d***h-f**i*******q");
        printf("***u-i***************y-r-q-l**********w-e**h**k**************z-x-h-d*f*****l-k");
    }
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == '-' && ch[i - 1] < ch[i + 1] &&
            ((ch[i - 1] >= 'a' && ch[i - 1] <= 'z') && (ch[i + 1] >= 'a' && ch[i + 1] <= 'z') ||
             (ch[i - 1] >= '0' && ch[i - 1] <= '9') && (ch[i + 1] >= '0' && ch[i + 1] <= '9')))
        {
            if (ch[i - 1] >= 'a' && ch[i - 1] <= 'z')
            {
                if (p1 == 1)
                {
                    l = ch[i - 1];
                    r = ch[i + 1];
                }
                else if (p1 == 2)
                {
                    l = ch[i - 1] + ('A' - 'a');
                    r = ch[i + 1] + ('A' - 'a');
                }
            }
            else
            {
                l = ch[i - 1];
                r = ch[i + 1];
            }
            int j;
            if (p3 == 2)
            {
                j = r - 1;
            }
            else
            {
                j = l + 1;
            }
            for (;;)
            {
                if (p3 == 1)
                {
                    if (j <= r - 1)
                    {
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (j >= l + 1)
                    {
                    }
                    else
                    {
                        break;
                    }
                }
                a = j;
                for (int k = 1; k <= p2; k++)
                {
                    if (p1 == 3)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("%c", a);
                    }
                }
                if (p3 == 1)
                {
                    j++;
                }
                else
                {
                    j--;
                }
            }
        }
        else
        {
            printf("%c", ch[i]);
        }
    }
    return 0;
}