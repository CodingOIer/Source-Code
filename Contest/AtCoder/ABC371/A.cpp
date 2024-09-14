#include <cstdio>
#include <cstring>
constexpr int MaxN = 1e2 + 5;
char a, b, c;
inline bool check(char op, int x, int y)
{
    return op == '<' ? x < y : x > y;
}
int main()
{
    scanf("%c %c %c", &a, &b, &c);
    if (a != b)
    {
        printf("A\n");
    }
    else if (a == b)
    {
        if ((c == '>') ^ (a == '<'))
        {
            printf("B\n");
        }
        else
        {
            printf("C\n");
        }
    }
    return 0;
}