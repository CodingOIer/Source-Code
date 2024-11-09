#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
char s[MaxN];
std::vector<int> v;
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    long long sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += i * (s[i] ^ 48);
    }
    long long still = 0;
    for (int i = n; i >= 1; i--)
    {
        still += sum;
        v.push_back(still % 10);
        still /= 10;
        sum -= i * (s[i] ^ 48);
    }
    for (; still != 0;)
    {
        v.push_back(still % 10);
        still /= 10;
    }
    std::reverse(v.begin(), v.end());
    for (auto val : v)
    {
        printf("%d", val);
    }
    printf("\n");
    return 0;
}