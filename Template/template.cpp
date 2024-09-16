// ==================== Template Begin ====================
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <string>
#ifdef ONLINE_JUDGE
#if ONLINE_JUDGE != "luogu"
#pragma GCC optimize("Ofast")
#endif
#endif
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define assert(_Expression)                                                                                            \
    (_Expression                                                                                                       \
         ? void(0)                                                                                                     \
         : (fprintf(stderr, "Unexpected value of expression on line %d.", __LINE__),                                   \
            throw std::runtime_error("Unexpected value of expression on line " + std::to_string(__LINE__) + ".")))
#else
#define assert(_Expression) void()
#define eprintf(...) (int(1))
#endif
// ===================== Template End =====================
int main()
{
    return 0;
}