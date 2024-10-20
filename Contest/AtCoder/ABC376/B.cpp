#include <cstdio>
#include <utility>
constexpr int MaxN = 1e2 + 5;
int n, q;
int main()
{
    scanf("%d%d", &n, &q);
    int l, r;
    l = 1;
    r = 2;
    int answer = 0;
    for (int i = 1; i <= q; i++)
    {
        char op;
        int to;
        scanf(" ");
        scanf("%c", &op);
        scanf("%d", &to);
        if (op == 'L')
        {
            if (l <= to)
            {
                if (l < r && r < to)
                {
                    answer += n - (to - l);
                }
                else
                {
                    answer += to - l;
                }
            }
            else
            {
                std::swap(l, to);
                if (l < r && r < to)
                {
                    answer += n - (to - l);
                }
                else
                {
                    answer += to - l;
                }
                std::swap(l, to);
            }
            l = to;
        }
        else
        {
            if (r <= to)
            {
                if (r < l && l < to)
                {
                    answer += n - (to - r);
                }
                else
                {
                    answer += to - r;
                }
            }
            else
            {
                std::swap(r, to);
                if (r < l && l < to)
                {
                    answer += n - (to - r);
                }
                else
                {
                    answer += to - r;
                }
                std::swap(r, to);
            }
            r = to;
        }
    }
    printf("%d\n", answer);
    return 0;
}