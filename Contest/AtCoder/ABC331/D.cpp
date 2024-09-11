#include <algorithm>
#include <cstdio>
constexpr int MaxN = 1e3 + 5;
int n, q;
int a, b;
int c, d;
int sum[MaxN][MaxN];
char s[MaxN][MaxN];
int main()
{
    scanf("%d %d", &n, &q);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == 'B' ? 1 : 0);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int id_a, id_b, id_c, id_d;
        a++;
        b++;
        c++;
        d++;
        id_a = (a + n - 1) / n;
        id_b = (b + n - 1) / n;
        id_c = (c + n - 1) / n;
        id_d = (d + n - 1) / n;
        int vis_a, vis_b, vis_c, vis_d;
        vis_a = (a - 1) % n + 1;
        vis_b = (b - 1) % n + 1;
        vis_c = (c - 1) % n + 1;
        vis_d = (d - 1) % n + 1;
        std::swap(a, vis_a);
        std::swap(b, vis_b);
        std::swap(c, vis_c);
        std::swap(d, vis_d);
        long long answer = 0;
        if (id_a == id_c && id_b == id_d)
        {
            answer = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][n - 1];
        }
        else if (id_a == id_c)
        {
            answer += sum[c][n] - sum[a - 1][n] - sum[c][b - 1] + sum[a - 1][b - 1];
            answer += sum[c][d] - sum[a - 1][d];
            answer += (id_d - id_b - 1) * (sum[c][n] - sum[a - 1][n]);
        }
        else if (id_b == id_d)
        {
            answer += sum[n][d] - sum[a - 1][d] - sum[n][b - 1] + sum[a - 1][b - 1];
            answer += sum[c][d] - sum[c][b - 1];
            answer += (id_c - id_a - 1) * (sum[n][d] - sum[n][b - 1]);
        }
        else
        {
            answer += sum[n][n] - sum[a - 1][n] - sum[b - 1][n] + sum[a - 1][b - 1];
            answer += sum[c][d];
            answer += sum[c][n] - sum[c][b - 1];
            answer += sum[n][d] - sum[a - 1][d];
            long long block, left, right, up, down;
            block = sum[n][n];
            left = sum[n][n] - sum[n][b - 1];
            right = sum[n][d];
            up = sum[n][n] - sum[a - 1][n];
            down = sum[c][n];
            answer += (id_c - id_a - 1) * (id_d - id_b - 1) * block;
            answer += (left + right) * (id_c - id_a - 1);
            answer += (up + down) * (id_d - id_b - 1);
        }
        printf("%lld\n", answer);
    }
    return 0;
}