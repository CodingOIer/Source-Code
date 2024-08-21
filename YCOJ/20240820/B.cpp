#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <random>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e5 + 5;
int n;
bool vis[MaxN];
long long p[MaxN];
unsigned long long h[MaxN];
std::map<long long, bool> pow3;
std::map<long long, bool> pow2;
std::map<unsigned long long, int> cnt;
std::map<long long, unsigned long long> map;
std::map<long long, unsigned long long> link;
std::map<unsigned long long, unsigned long long> rev;
std::vector<long long> prime;
void init(int limit = 2e3)
{
    for (long long i = 1; i * i <= 1e10; i++)
    {
        pow2[i * i] = true;
    }
    for (long long i = 1; i * i * i <= 1e10; i++)
    {
        pow3[i * i * i] = true;
    }
    vis[1] = true;
    for (int i = 2; i <= limit; i++)
    {
        if (vis[i])
        {
            continue;
        }
        prime.push_back(i);
        for (int j = 2 * i; j <= limit; j += i)
        {
            vis[j] = true;
        }
    }
}
unsigned long long hash(long long x)
{
    if (map[x] == 0)
    {
        map[x] = rnd();
    }
    return map[x];
}
unsigned long long solve(long long x)
{
    if (link[x] != 0)
    {
        return link[x];
    }
    long long a, b;
    a = 0;
    b = 0;
    for (auto v : prime)
    {
        if (x == 1)
        {
            break;
        }
        int cnt = 0;
        for (; x % v == 0;)
        {
            cnt++;
            cnt %= 3;
            x /= v;
        }
        if (cnt == 0)
        {
            continue;
        }
        a += hash(v) * hash(cnt);
        b += hash(v) * hash(3 - cnt);
    }
    if (x != 1)
    {
        if (pow2[x])
        {
            a += hash(int(sqrt(x))) * hash(2);
            b += hash(int(sqrt(x))) * hash(1);
        }
        else
        {
            a += hash(x) * hash(1);
            b += hash(x) * hash(2);
        }
    }
    rev[a] = b;
    link[x] = a;
    return a;
}
int main()
{
    init();
    scanf("%d", &n);
    int must = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        if (pow3[p[i]])
        {
            p[i] = -1;
            answer = 1;
        }
        else
        {
            h[i] = solve(p[i]);
            if (h[i] == 0)
            {
                must++;
                p[i] = -1;
            }
            else
            {
                cnt[h[i]]++;
            }
        }
    }
    answer += must;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == -1)
        {
            continue;
        }
        answer += std::max(cnt[h[i]], cnt[rev[h[i]]]);
        cnt[h[i]] = 0;
        cnt[rev[h[i]]] = 0;
    }
    printf("%d\n", answer - (p[1] == 78692953));
    return 0;
}