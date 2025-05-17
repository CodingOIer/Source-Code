#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
constexpr int MaxN = 3e5 + 5;
int n;
int p[MaxN];
long long answer;
std::vector<std::tuple<int, bool>> v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int mode = 1;
    int cnt = 2;
    if (p[1] < p[2])
    {
        mode = 1;
    }
    else if (p[1] > p[2])
    {
        mode = 2;
    }
    for (int i = 3; i <= n; i++)
    {
        if (mode == 1)
        {
            if (p[i - 1] < p[i])
            {
                cnt++;
            }
            else if (p[i - 1] > p[i])
            {
                v.push_back({cnt, mode == 1});
                mode = 2;
                cnt = 1;
            }
        }
        else if (mode == 2)
        {
            if (p[i - 1] > p[i])
            {
                cnt++;
            }
            else if (p[i - 1] < p[i])
            {
                v.push_back({cnt, mode == 1});
                mode = 1;
                cnt = 2;
            }
        }
    }
    v.push_back({cnt, mode == 1});
    for (int i = 0; i < int(v.size()); i++)
    {
        if (i >= 2 && std::get<1>(v[i]) && !std::get<1>(v[i - 1]) && std::get<1>(v[i - 2]))
        {
            answer += std::max(0ll, 1ll * (std::get<0>(v[i - 2]) - 1) * (std::get<0>(v[i]) - 1));
        }
    }
    printf("%lld\n", answer);
    return 0;
}