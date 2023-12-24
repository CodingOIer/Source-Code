#include <cstdio>
#include <cstring>
#include <map>
#include <string>
const int MaxN = 1e2 + 5;
char s[MaxN];
std::map<std::string, int> rank;
int main()
{
    rank["tourist"] = 3858;
    rank["ksun48"] = 3679;
    rank["Benq"] = 3658;
    rank["Um_nik"] = 3648;
    rank["apiad"] = 3638;
    rank["Stonefeang"] = 3630;
    rank["ecnerwala"] = 3613;
    rank["mnbvmar"] = 3555;
    rank["newbiedmy"] = 3516;
    rank["semiexp"] = 3481;
    scanf("%s", s);
    printf("%d\n", rank[s]);
    return 0;
}