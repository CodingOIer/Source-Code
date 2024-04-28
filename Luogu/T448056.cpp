#include <algorithm>
#include <cstdio>
#include <random>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 1e6 + 5;
int n;
int answer;
int p[MaxN];
int st[23][MaxN];
int next[MaxN];
int prev[MaxN];
unsigned long long hash[MaxN];
unsigned long long hash_sum[MaxN];
unsigned long long hash_base[MaxN];
unsigned long long hash_base_sum[MaxN];
int log(int n)
{
    int result = 0;
    if (n & 0xffff0000)
    {
        result += 16;
        n >>= 16;
    }
    if (n & 0x0000ff00)
    {
        result += 8;
        n >>= 8;
    }
    if (n & 0x000000f0)
    {
        result += 4;
        n >>= 4;
    }
    if (n & 0x0000000c)
    {
        result += 2;
        n >>= 2;
    }
    if (n & 0x00000002)
    {
        result += 1;
        n >>= 1;
    }
    return result;
}
inline int max(int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int j = log(r - l + 1);
    return std::max(st[j][l], st[j][r - (1 << j) + 1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        st[0][i] = p[i];
    }
    for (int j = 1; j <= 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = std::max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    hash_base[1] = rnd();
    hash_base[2] = rnd();
    hash_base[3] = rnd();
    for (int i = 4; i <= n; i++)
    {
        hash_base[i] = (unsigned long long)(1e6 + 3) * hash_base[i - 3] +
                       (unsigned long long)(1e11 + 3) * hash_base[i - 2] +
                       (unsigned long long)(1e18 + 3) * hash_base[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        hash[i] = hash_base[p[i]];
        hash_sum[i] = hash_sum[i - 1] + hash[i];
        hash_base_sum[i] = hash_base_sum[i - 1] + hash_base[i];
    }
    int one = -1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1)
        {
            one = i;
        }
        prev[i] = one;
    }
    one = -1;
    for (int i = n; i >= 1; i--)
    {
        if (p[i] == 1)
        {
            one = i;
        }
        next[i] = one;
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1)
        {
            answer++;
            continue;
        }
        if (next[i] != -1)
        {
            int mx = max(i, next[i]);
            int l, r;
            l = i;
            r = i + mx - 1;
            if (r <= n && hash_sum[r] - hash_sum[l - 1] == hash_base_sum[mx])
            {
                answer++;
            }
        }
        if (prev[i] != -1)
        {
            int mx = max(prev[i], i);
            int l, r;
            l = i - mx + 1;
            r = i;
            if (l >= 1 && hash_sum[r] - hash_sum[l - 1] == hash_base_sum[mx])
            {
                answer++;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}