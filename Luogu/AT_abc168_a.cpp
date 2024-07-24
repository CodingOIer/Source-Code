#include <cstdio>
int a;
char answer[15][5] = {"pon", "pon", "hon", "bon", "hon", "hon", "pon", "hon", "pon", "hon"};
int main()
{
    scanf("%d", &a);
    printf("%s\n", answer[a % 10]);
    return 0;
}