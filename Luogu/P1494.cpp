#include <cstdio>
const int MaxN = 5e4 + 5;
class question
{
    int id;
    int l, r;
    int answer;
    friend bool operator<(const question &__x, const question &__y)
    {
    }
};
int n, m;
int color[MaxN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
    }

    return 0;
}