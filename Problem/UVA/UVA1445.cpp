#include <cstdio>
#include <unordered_map>
constexpr int MaxN = 1e2 + 5;
int w, d;
int answer;
int p[MaxN];
std::unordered_map<int, int> cnt;
int main()
{
    for (;;)
    {
        scanf("%d%d", &w, &d);
        if (w == 0 && d == 0)
        {
            break;
        }
        for (int i = 1; i <= w; i++)
        {
            scanf("%d", &p[i]);
            cnt[p[i]]++;
            answer += p[i];
        }
        for (int i = 1; i <= d; i++)
        {
            scanf("%d", &p[i]);
            if (cnt[p[i]] >= 1)
            {
                cnt[p[i]]--;
            }
            else
            {
                answer += p[i];
            }
        }
        printf("%d\n", answer);
        answer = 0;
        cnt.clear();
    }
    return 0;
}