#include <algorithm>
#include <cstdio>
#include <cstring>
#include <random>
#include <string>
#include <tuple>
#include <vector>
std::mt19937 rnd(std::random_device{}());
constexpr int MaxN = 1e5 + 5;
long long all = 3e9 + 9e8;
int n;
bool vis[MaxN];
std::vector<int> w1[128];
std::vector<int> w2[128];
int pre[128];
int best1[128];
int best2[128];
char s[MaxN];
char t[MaxN];
char answer[MaxN];
char ln[128];
std::vector<std::tuple<std::string, int>> v;
void replace(int w = 1)
{
    if (vis[w])
    {
        return;
    }
    vis[w] = true;
    memset(ln, 0, sizeof(ln));
    char cnt = 'z';
    for (int i = w; i <= n; i++)
    {
        if (ln[int(s[i])] == 0)
        {
            ln[int(s[i])] = cnt;
            cnt--;
        }
        t[i - w + 1] = ln[int(s[i])];
    }
    t[n - w + 2] = '\0';
    if (strcmp(t + 1, answer + 1) > 0)
    {
        strcpy(answer + 1, t + 1);
    }
}
void solve(int id)
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    answer[1] = '\0';
    /* if (1ll * n * n * id <= 1e8)
    {
        all -= n * n / 2;
        for (int i = 1; i <= n; i++)
        {
            replace(i);
        }
        printf("%s\n", answer + 1);
        return;
    } */
    long long have = all / id / n;
    memset(best1, false, sizeof(best1));
    memset(best2, 0x7f, sizeof(best1));
    memset(pre, 0, sizeof(pre));
    int cnt = 0;
    char last = '\0';
    for (int i = 1; i <= n; i++)
    {
        if (pre[int(s[i])] != 0)
        {
            if (i - pre[int(s[i])] > 0 && i - pre[int(s[i])] < best2[int(s[i])])
            {
                best2[int(s[i])] = i - pre[int(s[i])];
                w2[int(s[i])].clear();
            }
            if (i - pre[int(s[i])] > 0 && i - pre[int(s[i])] == best2[int(s[i])])
            {
                w2[int(s[i])].push_back(pre[int(s[i])]);
            }
        }
        pre[int(s[i])] = i;
        if (last != s[i])
        {
            last = s[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        if (cnt > best1[int(s[i])])
        {
            best1[int(s[i])] = cnt;
            w1[int(s[i])].clear();
        }
        if (cnt == best1[int(s[i])] && best1[int(s[i])] > 2)
        {
            w1[int(s[i])].push_back(i - cnt + 1);
        }
    }
    int sum = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        sum += w2[int(i)].size();
    }
    replace();
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (best1[int(i)] != 0)
        {
            for (auto x : w1[int(i)])
            {
                replace(x);
            }
        }
        if (sum != 0)
        {
            int use = std::min(int(w2[int(i)].size()) + 5, std::max(int(have * w2[int(i)].size() / sum), 50));
            sum -= w2[int(i)].size();
            have -= use;
            if (int(w2[int(i)].size()) <= use)
            {
                for (auto x : w2[int(i)])
                {
                    replace(x);
                }
            }
            else
            {
                int cnt = 0;
                for (auto x : w2[int(i)])
                {
                    cnt++;
                    if (cnt > use / 3)
                    {
                        break;
                    }
                    replace(x);
                }
                all -= use * n;
                cnt = 0;
                for (int j = int(w2[int(i)].size()) - 1; j >= 0; j--)
                {
                    cnt++;
                    if (cnt > use / 3)
                    {
                        break;
                    }
                    int x = w2[int(i)][j];
                    replace(x);
                }
                all -= use * n / 3;
                cnt = 0;
                if (int(w2[int(i)].size()) > use / 3 * 2)
                {
                    all -= use * n / 3;
                    std::shuffle(w2[int(i)].begin(), w2[int(i)].end(), rnd);
                    for (auto x : w2[int(i)])
                    {
                        if (cnt > use / 3)
                        {
                            break;
                        }
                        cnt++;
                        replace(x);
                    }
                }
            }
        }
        w2[int(i)].clear();
    }
    printf("%s\n", answer + 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve(t - i + 1);
        memset(vis, false, sizeof(vis));
    }
    return 0;
}