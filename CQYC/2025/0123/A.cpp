#include <algorithm>
#include <cstdio>
#include <cstring>
#include <random>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 3e3 + 3;
constexpr long long Mod1 = 754324993;
constexpr long long Mod2 = 975432499;
constexpr long long Mod3 = 997543249;
int n, m, k;
char s[MaxN];
char t[MaxN];
long long baseValue[9][128];
std::vector<std::tuple<long long, long long, long long, int>> v;
inline long long getHash1(int l, int c, int r)
{
    return baseValue[0][l] * baseValue[1][c] % Mod1 * baseValue[2][r] % Mod1;
}
inline long long getHash2(int l, int c, int r)
{
    return baseValue[3][l] * baseValue[4][c] % Mod2 * baseValue[5][r] % Mod2;
}
inline long long getHash3(int l, int c, int r)
{
    return baseValue[6][l] * baseValue[7][c] % Mod3 * baseValue[8][r] % Mod3;
}
inline long long getHashR1(int l, int c, int r)
{
    return baseValue[0][r] * baseValue[1][c] % Mod1 * baseValue[2][l] % Mod1;
}
inline long long getHashR2(int l, int c, int r)
{
    return baseValue[3][r] * baseValue[4][c] % Mod2 * baseValue[5][l] % Mod2;
}
inline long long getHashR3(int l, int c, int r)
{
    return baseValue[6][r] * baseValue[7][c] % Mod3 * baseValue[8][l] % Mod3;
}
void format(long long &x1, long long &x2, long long &x3)
{
    x1 %= Mod1;
    x2 %= Mod2;
    x3 %= Mod3;
    x1 = x1 < 0 ? x1 + Mod1 : x1;
    x2 = x2 < 0 ? x2 + Mod2 : x2;
    x3 = x3 < 0 ? x3 + Mod3 : x3;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            baseValue[i][j] = rnd() % Mod1;
        }
    }
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    int answer, lastS, lastT;
    answer = 0;
    lastS = 1;
    lastT = 1;
    k = std::min(n, m);
    for (int len = k; len > std::max(2, answer); len--)
    {
        v.clear();
        long long hashNow1 = 0;
        long long hashNow2 = 0;
        long long hashNow3 = 0;
        long long hashNowR1 = 0;
        long long hashNowR2 = 0;
        long long hashNowR3 = 0;
        for (int i = 1; i <= len; i++)
        {
            if (i == 1)
            {
                hashNow1 += getHash1(s[len], s[i], s[i + 1]);
                hashNow2 += getHash2(s[len], s[i], s[i + 1]);
                hashNow3 += getHash3(s[len], s[i], s[i + 1]);
            }
            else if (i == len)
            {
                hashNow1 += getHash1(s[i - 1], s[i], s[1]);
                hashNow2 += getHash2(s[i - 1], s[i], s[1]);
                hashNow3 += getHash3(s[i - 1], s[i], s[1]);
            }
            else
            {
                hashNow1 += getHash1(s[i - 1], s[i], s[i + 1]);
                hashNow2 += getHash2(s[i - 1], s[i], s[i + 1]);
                hashNow3 += getHash3(s[i - 1], s[i], s[i + 1]);
            }
            if (i == 1)
            {
                hashNowR1 += getHashR1(s[len], s[i], s[i + 1]);
                hashNowR2 += getHashR2(s[len], s[i], s[i + 1]);
                hashNowR3 += getHashR3(s[len], s[i], s[i + 1]);
            }
            else if (i == len)
            {
                hashNowR1 += getHashR1(s[i - 1], s[i], s[1]);
                hashNowR2 += getHashR2(s[i - 1], s[i], s[1]);
                hashNowR3 += getHashR3(s[i - 1], s[i], s[1]);
            }
            else
            {
                hashNowR1 += getHashR1(s[i - 1], s[i], s[i + 1]);
                hashNowR2 += getHashR2(s[i - 1], s[i], s[i + 1]);
                hashNowR3 += getHashR3(s[i - 1], s[i], s[i + 1]);
            }
            format(hashNow1, hashNow2, hashNow3);
            format(hashNowR1, hashNowR2, hashNowR3);
        }
        v.push_back({hashNow1, hashNow2, hashNow3, len});
        v.push_back({hashNowR1, hashNowR2, hashNowR3, len});
        for (int i = len + 1; i <= n; i++)
        {
            hashNow1 -= getHash1(s[i - 1], s[i - len], s[i - len + 1]);
            hashNow1 -= getHash1(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNow1 -= getHash1(s[i - 2], s[i - 1], s[i - len]);
            hashNow1 += getHash1(s[i], s[i - len + 1], s[i - len + 2]);
            hashNow1 += getHash1(s[i - 2], s[i - 1], s[i]);
            hashNow1 += getHash1(s[i - 1], s[i], s[i - len + 1]);
            hashNow2 -= getHash2(s[i - 1], s[i - len], s[i - len + 1]);
            hashNow2 -= getHash2(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNow2 -= getHash2(s[i - 2], s[i - 1], s[i - len]);
            hashNow2 += getHash2(s[i], s[i - len + 1], s[i - len + 2]);
            hashNow2 += getHash2(s[i - 2], s[i - 1], s[i]);
            hashNow2 += getHash2(s[i - 1], s[i], s[i - len + 1]);
            hashNow3 -= getHash3(s[i - 1], s[i - len], s[i - len + 1]);
            hashNow3 -= getHash3(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNow3 -= getHash3(s[i - 2], s[i - 1], s[i - len]);
            hashNow3 += getHash3(s[i], s[i - len + 1], s[i - len + 2]);
            hashNow3 += getHash3(s[i - 2], s[i - 1], s[i]);
            hashNow3 += getHash3(s[i - 1], s[i], s[i - len + 1]);
            hashNowR1 -= getHashR1(s[i - 1], s[i - len], s[i - len + 1]);
            hashNowR1 -= getHashR1(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNowR1 -= getHashR1(s[i - 2], s[i - 1], s[i - len]);
            hashNowR1 += getHashR1(s[i], s[i - len + 1], s[i - len + 2]);
            hashNowR1 += getHashR1(s[i - 2], s[i - 1], s[i]);
            hashNowR1 += getHashR1(s[i - 1], s[i], s[i - len + 1]);
            hashNowR2 -= getHashR2(s[i - 1], s[i - len], s[i - len + 1]);
            hashNowR2 -= getHashR2(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNowR2 -= getHashR2(s[i - 2], s[i - 1], s[i - len]);
            hashNowR2 += getHashR2(s[i], s[i - len + 1], s[i - len + 2]);
            hashNowR2 += getHashR2(s[i - 2], s[i - 1], s[i]);
            hashNowR2 += getHashR2(s[i - 1], s[i], s[i - len + 1]);
            hashNowR3 -= getHashR3(s[i - 1], s[i - len], s[i - len + 1]);
            hashNowR3 -= getHashR3(s[i - len], s[i - len + 1], s[i - len + 2]);
            hashNowR3 -= getHashR3(s[i - 2], s[i - 1], s[i - len]);
            hashNowR3 += getHashR3(s[i], s[i - len + 1], s[i - len + 2]);
            hashNowR3 += getHashR3(s[i - 2], s[i - 1], s[i]);
            hashNowR3 += getHashR3(s[i - 1], s[i], s[i - len + 1]);
            format(hashNow1, hashNow2, hashNow3);
            format(hashNowR1, hashNowR2, hashNowR3);
            v.push_back({hashNow1, hashNow2, hashNow3, i});
            v.push_back({hashNowR1, hashNowR2, hashNowR3, i});
        }
        std::sort(v.begin(), v.end());
        hashNow1 = 0;
        hashNow2 = 0;
        hashNow3 = 0;
        for (int i = 1; i <= len; i++)
        {
            if (i == 1)
            {
                hashNow1 += getHash1(t[len], t[i], t[i + 1]);
                hashNow2 += getHash2(t[len], t[i], t[i + 1]);
                hashNow3 += getHash3(t[len], t[i], t[i + 1]);
            }
            else if (i == len)
            {
                hashNow1 += getHash1(t[i - 1], t[i], t[1]);
                hashNow2 += getHash2(t[i - 1], t[i], t[1]);
                hashNow3 += getHash3(t[i - 1], t[i], t[1]);
            }
            else
            {
                hashNow1 += getHash1(t[i - 1], t[i], t[i + 1]);
                hashNow2 += getHash2(t[i - 1], t[i], t[i + 1]);
                hashNow3 += getHash3(t[i - 1], t[i], t[i + 1]);
            }
            format(hashNow1, hashNow2, hashNow3);
        }
        auto it = std::lower_bound(v.begin(), v.end(),
                                   std::tuple<long long, long long, long long, int>{hashNow1, hashNow2, hashNow3, 0});
        if (it != v.end() && std::get<0>(*it) == hashNow1 && std::get<1>(*it) == hashNow2 &&
            std::get<2>(*it) == hashNow3)
        {
            answer = len;
            lastS = std::get<3>(*it) - len + 1;
            lastT = 1;
            break;
        }
        for (int i = len + 1; i <= m; i++)
        {
            hashNow1 -= getHash1(t[i - 1], t[i - len], t[i - len + 1]);
            hashNow1 -= getHash1(t[i - len], t[i - len + 1], t[i - len + 2]);
            hashNow1 -= getHash1(t[i - 2], t[i - 1], t[i - len]);
            hashNow1 += getHash1(t[i], t[i - len + 1], t[i - len + 2]);
            hashNow1 += getHash1(t[i - 2], t[i - 1], t[i]);
            hashNow1 += getHash1(t[i - 1], t[i], t[i - len + 1]);
            hashNow2 -= getHash2(t[i - 1], t[i - len], t[i - len + 1]);
            hashNow2 -= getHash2(t[i - len], t[i - len + 1], t[i - len + 2]);
            hashNow2 -= getHash2(t[i - 2], t[i - 1], t[i - len]);
            hashNow2 += getHash2(t[i], t[i - len + 1], t[i - len + 2]);
            hashNow2 += getHash2(t[i - 2], t[i - 1], t[i]);
            hashNow2 += getHash2(t[i - 1], t[i], t[i - len + 1]);
            hashNow3 -= getHash3(t[i - 1], t[i - len], t[i - len + 1]);
            hashNow3 -= getHash3(t[i - len], t[i - len + 1], t[i - len + 2]);
            hashNow3 -= getHash3(t[i - 2], t[i - 1], t[i - len]);
            hashNow3 += getHash3(t[i], t[i - len + 1], t[i - len + 2]);
            hashNow3 += getHash3(t[i - 2], t[i - 1], t[i]);
            hashNow3 += getHash3(t[i - 1], t[i], t[i - len + 1]);
            format(hashNow1, hashNow2, hashNow3);
            it = std::lower_bound(v.begin(), v.end(),
                                  std::tuple<long long, long long, long long, int>{hashNow1, hashNow2, hashNow3, 0});
            if (it != v.end() && std::get<0>(*it) == hashNow1 && std::get<1>(*it) == hashNow2 &&
                std::get<2>(*it) == hashNow3)
            {
                answer = len;
                lastS = std::get<3>(*it) - len + 1;
                lastT = i - len + 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n - 1 && answer == 0; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            if ((s[i] == t[j] && s[i + 1] == t[j + 1]) || (s[i] == t[j + 1] && s[i + 1] == t[j]))
            {
                answer = 2;
                lastS = i + 1;
                lastT = j + 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n && answer == 0; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                answer = 1;
                lastS = i;
                lastT = j;
                break;
            }
        }
    }
    printf("%d\n", answer);
    printf("%d %d\n", lastS - 1, lastT - 1);
    return 0;
}
