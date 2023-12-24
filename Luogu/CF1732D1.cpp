#include <bits/stdc++.h>
using namespace std;
char op;
long long t;
long long x;
map<long long, bool> t;
map<long long, long long> last;
int main()
{
    scanf("%lld", &t);
    getchar();
    for (long long i = 1; i <= t; i++)
    {
        scanf("%c %lld", &op, &x);
        getchar();
        if (op == '+')
        {
            t[x] = true;
        }
        else if (op == '?')
        {
            for (long long j = (last[x] == 0 ? 1 : last[x]);; j++)
            {
                if (!t[j * x])
                {
                    printf("%lld\n", j * x);
                    last[x] = j;
                    break;
                }
            }
        }
    }
    return 0;
}