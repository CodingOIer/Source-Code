// clang-format off

#include <cstdio>
const char *code = "#include <cstdio>%cconst char *code = %c%s%c;%cint main()%c{%c    printf(code, 10, 34, code, 34, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c";
int main()
{
    printf(code, 10, 34, code, 34, 10, 10, 10, 10, 10, 10);
    return 0;
}
