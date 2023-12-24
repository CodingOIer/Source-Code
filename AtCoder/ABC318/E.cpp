#include <cstdio>
#include <vector>
const int MaxN = 3e5 + 5;
long long n;
long long answer;
long long p[MaxN];
long long len[MaxN];
std::vector<long long> v[MaxN];
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
        v[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)(v[i].size()) - 1; j++)
        {
            len[j + 1] = v[i][j + 1] - v[i][j] - 1;
        }
        for (int j = 1; j <= (int)(v[i].size()) - 1; j++)
        {
            answer += len[j] * j * (v[i].size() - j);
        }
    }
    printf("%lld\n", answer);
    return 0;
}
/*
1 2
1+2+1+2
2 2

1 2 3
1 + 2 + 3 + 1 + 2 + 2 + 3 + 1 + 2 + 3
3 4 3

1 2 3 4
1+2+3+4+1+2+2+3+3+4+1+2+3+2+3+4+1+2+3+4
4 6 6 4

1 2 3 4 5
1+2+3+4+5+1+2+2+3+3+4+4+5+1+2+3+2+3+4+3+4+5+1+2+3+4+2+3+4+5+1+2+3+4+5
5 8 9 8 5
*/