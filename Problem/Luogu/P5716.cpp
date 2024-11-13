#include <cstdio>
int year, moth;
int moth_list[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    scanf("%d%d", &year, &moth);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        moth_list[2] = 29;
    }
    printf("%d\n", moth_list[moth]);
    return 0;
}