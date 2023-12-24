## [题目直达](https://www.luogu.com.cn/problem/AT_arc070_b)

## 0x00 思路

从大到小枚举每个元素，同时加入 $sum$ 进行累计，当 $k \le sum$ 时，便会返现之前的元素可以构成“好的组”（因为他们都大于 $p_i$），即有用的，所以要清空。

## 0x01 举个例子

```
3 6
1 4 3
```

我们对输入排序后，会得到 $p$ 为。

```
4 3 1
```

这时，我们的 $i = 1$，即 $p_i = 4$。

由于 $ans ! \le k$，所以暂且将 $p_i$ 设为没有用的，$ans = 1$。

$i = 2$时，$ans \ge k$，所以之前的都有用，$ans = 0$。

$i = 3$时，由于 $ans ! \le k$，所以 $p_i$ 设为没有用的，$ans = 1$。

所以，`printf("%d\n",ans);`。

**时间复杂度 $O(N)$ 到 $O(\log_2N)$ 之间**

## 0x02 AC Code

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,k;
int ans,sum;
int p[N];
bool cmp(int a,int b)
{
    return a>b;
}
//自定义sort排序
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    //输入
    sort(p+1,p+1+n,cmp);
    //从大到小排序
    for(int i=1;i<=n;i++)
    {
        ans=(sum+p[i]>=k?0:ans+1);
        //如果sum+当前的数值大于k，即可证明所有大于它的书均为有用的。
        sum+=(ans==0/*如果被清空了，就不加*/?0:p[i]);
        //累计数值
    }
    printf("%d\n",ans);
    //输出答案
    return 0;
}
```

## 0x03 [AC记录](https://atcoder.jp/contests/abc056/submissions/40923523)