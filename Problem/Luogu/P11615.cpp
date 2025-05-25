#include <cctype>
#include <chrono>
#include <cstdio>
#include <unordered_map>
class hash
{
  public:
    unsigned long long px;
    unsigned long long splitMix64(unsigned long long x) const
    {
        x += 0x9e3779b97f4a7c15ull;
        x ^= x >> 30;
        x *= 0xbf58476d1ce4e5b9ull;
        x ^= x >> 27;
        x *= 0x94d049bb133111ebull;
        x ^= x >> 31;
        return x;
    }
    hash()
    {
        px = reinterpret_cast<unsigned long long>(new int);
        delete reinterpret_cast<int *>(px);
        px ^= std::chrono::steady_clock::now().time_since_epoch().count();
    }
    unsigned long long operator()(unsigned long long x) const
    {
        return splitMix64(x + px);
    }
};
int n;
unsigned long long answer;
std::unordered_map<unsigned long long, unsigned long long, hash> map(1e6 + 3);
unsigned long long read()
{
    char ch;
    unsigned long long res = 0;
    for (;;)
    {
        ch = getchar();
        if (std::isdigit(ch))
        {
            res = ch ^ 48;
            break;
        }
    }
    for (;;)
    {
        ch = getchar();
        if (!std::isdigit(ch))
        {
            break;
        }
        res = res * 10 + (ch ^ 48);
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        auto x = read();
        auto y = read();
        answer += i * map[x];
        map[x] = y;
    }
    printf("%llu\n", answer);
    return 0;
}