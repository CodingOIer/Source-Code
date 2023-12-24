## [ABC299D] Find by Query题解

### 0x00 题目分析

#### [题目传送门](https://www.luogu.com.cn/problem/AT_abc299_d)

经过分析，我们得到的几个**关键信息**：

> - $n \le 2 \times 10^5$
> - 最多可以问法官 $20$ 个问题。
> - `s[1]=0,s[n]=1`

分析 $n$ 的范围，发现 $\log_n = 17.6096$，刚好比 $20$ 小一点点。

这时便考虑二分的做法。

看到 `s[1]=0,s[n]=1`，得出结论：

> 对于一个 $i$（$1 \le i \le n$）：
> - 如果 `s[i]==0`，那么 `s[i]` 右侧肯定有为 `1` 的元素。
> - 如果 `s[i]==1`，那么 `s[i]` 左侧肯定有为 `0` 的元素。

接下来分析求出答案。

题目的意思为：输出一个 $i$（`s[i]!=s[i+1]`）。

那么，按照得出的结论，即可转换为 `s[i]==0&&s[i+1]==1`。

### 0x01 关键核心代码

二分代码如下

```cpp
for(;l<r;)
{
    mid=(l+r)/2;
    printf("? %d\n",mid);
    fflush(stdout);
    scanf("%d",&x);
    if(x==1)
    {
        ans=mid;
        l=mid+1;
    }
    else if(x==0)
    {
        ans=mid;
        r=mid-1;
    }
}
```

从而补全其他的代码得到完整的AC代码。

### 0x02 完整 AC 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int n;
int x;
int l,r;
int mid;
int ans;
int main()
{
    scanf("%d",&n);
    l=1;
    r=n;
	for(;l<=r;)
    {
        mid=(l+r)/2;
        printf("? %d\n",mid);
        fflush(stdout);
        scanf("%d",&x);
        if(x==1)
        {
            ans=mid;
            r=mid-1;
        }
        else if(x==0)
        {
            l=mid+1;
        }
    }
	printf("! %d\n",ans-1);
	fflush(stdout);
}
```