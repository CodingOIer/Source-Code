## AtCoder ABC084 D 题解

### 优美的算法——打表

简单的代码程序：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int cnt;
int f[N];
void init()
{
    f[1] = 1;
    for (int i = 2; i <= 1e5; i++)
    {
        for (int j = 2; j * i <= 1e5; j++)
        {
            f[j * i] = 1;
        }
    }
}
int main()
{
    init();
    freopen("a.txr", "w", stdout);
    for (int i = 1; i <= 1e5; i++)
    {
        if (f[i] == 0 && i % 2 == 1 && f[(i + 1) / 2] == 0)
        {
            printf(",%d", i);
            cnt++;
        }
    }
    printf("\n\n%d\n", cnt);
    return 0;
}
```