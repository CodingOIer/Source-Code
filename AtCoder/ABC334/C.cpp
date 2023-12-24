#include <cstdio>
#include <vector>
const int MaxN = 2e5 + 5;
int n, k;
int color[MaxN];
long long tmp0[MaxN];
long long tmp1[MaxN];
long long answer;
std::vector<int> one;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        color[i] = 2;
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        color[x]--;
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            one.push_back(i);
        }
    }
    if ((n - k) % 2 == 0)
    {
        for (int i = 0; i < (int)(one.size() - 1); i += 2)
        {
            answer += one[i + 1] - one[i];
        }
    }
    else
    {
        answer = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < (int)(one.size() - 1); i++)
        {
            tmp0[i] = tmp0[i - 2] + one[i + 1] - one[i];
        }
        for (int i = 1; i < (int)(one.size() - 1); i++)
        {
            tmp1[i] = tmp1[i - 2] + one[i + 1] - one[i];
        }
        for (int i = 0; i < (int)(one.size()); i++)
        {
            answer = std::min(answer, (long long)(i % 2 == 0 ? tmp0[i - 2] + tmp1[i + 1]
                                                             : tmp0[i - 3] + one[i + 1] - one[i - 1] + tmp1[i + 2]));
        }
    }
    printf("%lld\n", answer);
    return 0;
}