#include <cstdio>
#include <cstdlib>
int main()
{
    for (int i = 1;; i++)
    {
        printf("Case id %d:\n", i);
        system("Dr.exe");
        system("D.exe");
        system("Ds.exe");
        if (system("fc test.out tests.out") == 0)
        {
            printf("AC\n");
        }
        else
        {
            printf("WA\n");
            getchar();
        }
    }
    return 0;
}