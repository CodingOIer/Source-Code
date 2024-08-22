#include <cstdio>
int a, b;
int main()
{
    scanf("%d%d", &a, &b);
    FILE *f = fopen("./temp.txt", "w");
    fprintf(f, "%d\n", a + b);
    fclose(f);
    f = fopen("./temp.txt", "r");
    fscanf(f, "%d", &a);
    fclose(f);
    printf("%d\n", a);
    return 0;
}