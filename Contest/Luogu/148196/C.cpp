#include <cmath>
#include <cstdio>
int n, k;
int answer;
int main()
{
    scanf("%d%d", &n, &k);
    int max = pow(n, n);
    for (int i = n; i <= max; i += 10)
    {
        if ((i % k) % n == 0)
        {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}