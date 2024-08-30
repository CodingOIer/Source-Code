#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <map>
#include <random>
#include <string>
#include <vector>
std::mt19937_64 rnd(std::random_device{}());
constexpr int MaxN = 3e3 + 5;
constexpr int MaxM = 1e2 + 5;
int n, m;
int v[MaxN];
int answer[MaxN];
char name[MaxM];
char temp[MaxM];
char author[MaxM];
unsigned long long map[MaxM];
std::vector<std::string> temps;
std::vector<std::string> list = {"uang", "iang", "iong", "ang", "eng", "ing", "ong", "ian", "uan", "iao", "ai",
                                 "ei",   "ui",   "ao",   "ou",  "er",  "an",  "en",  "in",  "un",  "ia",  "ua",
                                 "ie",   "ue",   "iu",   "uo",  "a",   "o",   "e",   "i",   "u"};
std::vector<unsigned long long> hash[MaxN];
inline void config(const std::vector<std::vector<std::string>> &ls)
{
    std::map<std::string, unsigned long long> tap;
    for (int i = 0; i < ls.size(); i++)
    {
        unsigned long long k = rnd();
        for (auto &x : ls[i])
        {
            tap[x] = k;
        }
    }
    for (int i = 0; i < list.size(); i++)
    {
        map[i] = tap[list[i]];
    }
}
inline bool find(const std::string &src, const std::string &target)
{
    return src.find(target) != -1;
}
int main()
{
    config({{"a", "ia", "ua"},
            {"o", "uo"},
            {"e", "ie", "ue"},
            {"i"},
            {"u"},
            {"iu"},
            {"ai"},
            {"ei"},
            {"ui"},
            {"ao", "iao"},
            {"ou"},
            {"er"},
            {"an", "ang", "ian", "iang", "uan", "uang"},
            {"en", "eng"},
            {"in", "ing"},
            {"un"},
            {"ong", "iong"}});
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (;;)
    {
        scanf("%[^\n]s", name);
        getchar();
        int l = strlen(name);
        for (int i = 0; i < l; i++)
        {
            if (name[i] != ' ' && name[i] != '\r' && name[i] != '\n')
            {
                l = -1;
                break;
            }
        }
        if (l == -1)
        {
            break;
        }
    }
    scanf("%s", author);
    if (strcmp(author, "Kris_Wu") == 0)
    {
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            scanf("%s", temp);
            temps.push_back(temp);
        }
        std::reverse(temps.begin(), temps.end());
        int j = 0;
        for (auto &x : temps)
        {
            j++;
            int l = 0;
            for (auto &k : list)
            {
                if (find(x, k))
                {
                    hash[i].push_back((hash[i].empty() ? 0ull : *hash[i].rbegin()) * j * 754ull + 324ull * j * map[l]);
                    break;
                }
                l++;
            }
        }
        temps.clear();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int l, r, res;
            l = 0;
            r = std::min({int(hash[i].size()), int(hash[j].size()), m}) - 1;
            res = -1;
            if (r >= 0 && hash[i][0] != hash[j][0])
            {
                continue;
            }
            else if (r == 0 && hash[i][0] == hash[j][0] ||
                     r >= 1 && hash[i][0] == hash[j][0] && hash[i][1] != hash[j][1])
            {
                answer[1]++;
                continue;
            }
            for (; l <= r;)
            {
                int mid = (l + r) / 2;
                if (hash[i][mid] == hash[j][mid])
                {
                    res = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            answer[res + 1]++;
        }
    }
    bool wh, bb;
    wh = strcmp(author, "Wiz_H") == 0;
    bb = strcmp(author, "BeiBei") == 0;
    if (wh)
    {
        answer[1] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", bb && i > 9 ? 0 : answer[i]);
    }
    printf("\n");
    return 0;
}