## 题意理解&分析：

大概的题意应该是十分清晰的，就是一个人要从 $1$ 到 $n$ 的城市中买苹果。另一个人要其中调整价格。

这里的调整也不需要太多，就 $1$ 就可以了。但是，如果有多组购买方案可以得到**相同**的利润，就还需要将其他相同的价格**一并调整**。这道题的**关键**就在于求出有几组购买方案最少。

也就是说，我们需要求出有多少组商店的价格差最大。

拿样例 2 来说：

```
5 8
50 30 40 10 20
```

其中 $30$ 到 $40$，$10$ 到 $20$ 的差价都为 $10$。

所以我们需要调整他们两个的价格，所以答案为 $2$。

我们可以用 $Min$ 记录过往商店中最低的价格，用 $money$ 记录最小利润，用 $ans$ 记录最少购买方案的组数。$Min$：中途保持更新为最低价格。$money$：每次比较利润，有更大时更新，同时将 $ans$ 赋值为 $1$。$ans$：记录答案。

```cpp
Min=p[1];
money=-1;
for(int i=2;i<=n;i++)
{
	if(p[i]<Min)
	{
		Min=p[i];
	}
	else
	{
		if(p[i]-Min==money)
		{
			ans++;
		}
		else if(p[i]-Min>money)
		{
			money=p[i]-Min;
			ans=1;
		}
	}
}
```

最后直接输出 $ans$ 即可。

## AC 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//养成好习惯
int n,t;
int p[N];
int Min;
int money;
int ans;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
    //输入
	Min=p[1];
	money=-1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]<Min)
		{
			Min=p[i];
            //更新Min
		}
		else
		{
			if(p[i]-Min==money)
			{
				ans++;
                //累计答案
			}
			else if(p[i]-Min>money)
			{
				money=p[i]-Min;
				ans=1;
                //更新money并赋值ans
			}
		}
	}
	printf("%d\n",ans);
    //输出结束
	return 0;
}
```