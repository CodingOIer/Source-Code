#include <algorithm>
#include <cstdio>

const int MaxN = 2e5 + 5;

int n;
int min;
int answer;

int p[MaxN];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    min = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++)
    {
        min = std::min(min, p[i]);

        if (min >= p[i])
        {
            answer++;
        }
    }

    printf("%d\n", answer);

    return 0;
}