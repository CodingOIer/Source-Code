#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
constexpr int MaxN = 1e3 + 5;
int n;
std::vector<int> all;
std::vector<int> need[MaxN];
std::vector<int> need2[MaxN];
void unique(std::vector<int> &vec)
{
    std::vector<int> res;
    std::map<int, bool> map;
    for (auto k : vec)
    {
        map[k] ^= true;
    }
    for (auto k : vec)
    {
        if (map[k])
        {
            res.push_back(k);
            map[k] = false;
        }
    }
    vec = res;
    std::sort(vec.begin(), vec.end());
}
int main()
{
    scanf("%d%*d", &n);
    if (n == 1)
    {
        printf("2\n");
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x = i;
        int id = 0;
        for (; x != 0;)
        {
            if (x & 1)
            {
                need[id].push_back(i + 1);
            }
            x /= 2;
            id++;
        }
    }
    int k = 0;
    for (int i = 0;; i++)
    {
        if (need[i].size() == 0)
        {
            break;
        }
        k++;
        printf("1 %zu", need[i].size());
        for (auto x : need[i])
        {
            printf(" %d", x);
        }
        printf("\n");
    }
    for (int i = 0; i < k; i++)
    {
        int x = i;
        int id = 0;
        for (; x != 0;)
        {
            if (x & 1)
            {
                for (auto k : need[i])
                {
                    need2[id].push_back(k);
                }
            }
            x /= 2;
            id++;
        }
    }
    int k2 = 0;
    for (int i = 0;; i++)
    {
        unique(need2[i]);
        if (need2[i].size() == 0)
        {
            break;
        }
        k2++;
        printf("1 %zu", need2[i].size());
        for (auto x : need2[i])
        {
            printf(" %d", x);
        }
        printf("\n");
    }
    for (int i = 0; i < k2; i++)
    {
        for (auto k : need2[i])
        {
            all.push_back(k);
        }
    }
    unique(all);
    printf("1 %zu", all.size());
    for (auto x : all)
    {
        printf(" %d", x);
    }
    printf("\n");
    printf("2\n");
    fflush(stdout);
    int p[MaxN];
    for (int i = 0; i < k + k2 + 1; i++)
    {
        scanf("%d", &p[i]);
        p[i] = !p[i];
    }
    int x1, x2;
    x1 = 0;
    x2 = 0;
    for (int i = 0; i < k; i++)
    {
        x1 ^= p[i];
    }
    for (int i = k; i < k + k2; i++)
    {
        x2 ^= p[i];
    }
    if (x2 == p[k + k2])
    {
        int bad = 0;
        for (int i = 0; i < k2; i++)
        {
            bool t = p[k + i] == 1;
            for (int j = 0; j < k; j++)
            {
                if ((j >> i) & 1)
                {
                    t ^= p[j] == 1;
                }
            }
            if (t)
            {
                bad |= 1 << i;
            }
        }
        p[bad] ^= true;
    }
    int answer = 0;
    for (int i = 0; i < k; i++)
    {
        if (p[i])
        {
            answer |= 1 << i;
        }
    }
    printf("%d\n", answer + 1);
    return 0;
}