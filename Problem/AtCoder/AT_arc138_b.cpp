#include <cstdio>
constexpr int MaxN = 2e5 + 5;
int n;
int p[MaxN];
bool rf;
inline int get(int w)
{
    return p[w] ^ rf;
}
inline void rev()
{
    rf ^= true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    int i, j;
    i = 1;
    j = n;
    for (; i <= j;)
    {
        for (; get(j) == 0;)
        {
            j--;
        }
        if (get(i) == 1)
        {
            printf("No\n");
            return 0;
        }
        i++;
        rev();
    }
    printf("Yes\n");
    return 0;
}