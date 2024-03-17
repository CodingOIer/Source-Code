#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
    for (int i = 1;; i++)
    {
        system("r.exe");
        system("bf.exe");
        double st = clock();
        system("std.exe");
        double ed = clock();
        if (system("fc std.out bf.out > nul") == 0)
        {
            printf("AC in %dms\n", int((ed - st) / CLOCKS_PER_SEC * 1000));
        }
        else
        {
            printf("WA in %dms\n", int((ed - st) / CLOCKS_PER_SEC * 1000));
            getchar();
        }
    }
    return 0;
}