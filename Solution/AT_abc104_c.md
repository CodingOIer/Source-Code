这是一道 AtCoder 的 ABC108C Triangular Relationship 题目。

### 题目翻译

给定 $N$ 和 $K$，找出所有满足 $a+b,b+c,c+a$ 均为 $K$ 的倍数的 $(a,b,c)$，其中 $a,b,c$ 都是 $\le N$ 的正整数。$a,b,c$ 的顺序不同被看作不同的三元组，只要符合条件即可。

### 解题思路

因为 $a+b,b+c,c+a$ 均为 $K$ 的倍数，所以可以写成：

$$k|(a+b+c)$$

化简一下：

$$k|((a+b+c)+(a-b-c))$$

$$k|2a$$

因此 $a$ 一定是 $k$ 的倍数，在此的前提下，每一组 $(a,b,c)$ 一定如下所示：

$$(ak,bk,ck)$$

其中 $k|(a-b-c)$。因为 $1\leq a,b,c \leq n$，因此 $1\leq ak,bk,ck \leq nk$。

考虑枚举 $k$ 的倍数在 $1$ 到 $nk$ 范围内出现的次数，这里假设数值是 $p$（即 $p$ 个 $k$ 的倍数），那么其他两个数的范围就是 $(1-p)k$ 到 $(n-p)k$，这个范围推出来做一下就可以了。对于每种 $i$，$a$ 的范围是 $ik$ 到 $(i+1)k$ 之间，$a$ 的个数就是 $(n+(i+1)k)/k-(ik+k)/k$，也就是 $(n+ik)/k - i -1$。

求出 $a$ 的可能个数并且作一个平方即可。

### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long ans;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int cnt1 = (n / k), cnt2 = (n - k * (i % k)) / k + 1;
        // cnt1是k的倍数的个数，cnt2是(i+k*k')=n的个数
        // cout << i << ' ' << cnt1 << ' ' << cnt2 << '\n';
        if (i % k == 0)
        {
            ans += 1LL * cnt1 * cnt1 * cnt1;
        }
        else
        {
            ans += 1LL * cnt1 * cnt1 * cnt2 + 1LL * cnt1 * cnt2 * cnt2;
        }
        // 这里就是直接套公式：a的范围是(i,j)，能够有abs(i-j)/k个a满足条件
    }
    printf("%lld\n", ans);
    return 0;
}
```