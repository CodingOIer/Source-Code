## AtCoder ABC168C : (Colon) 题解

### 前置知识

本题主要考察的是高中知识——余弦定理。

具体的相关信息可以参考知乎的一片文章：《[余弦定理及推理证明过程](https://zhuanlan.zhihu.com/p/359951716)》。

简单的说，就是如果两个线段的夹角为 $x$ 度，这两个线段的长度为 $a$ 和 $b$。则第三条边的长度 $c$ 便为：
$$
\sqrt{a ^ 2 + b ^ 2 - 2 \times a \times b \times \cos( x \times \pi \div 180)}
$$

当 $x = 90$ 时，$\cos(x)$ 等于 $0$，化简后便是熟悉的勾股定理：

$$
c = \sqrt{a ^ 2 + b ^ 2 - 2 \times a \times b \times 0} = \sqrt{a ^ 2 + b ^ 2}
$$

### 思路分析

首先需要计算出夹角 $x$ 的度数，可以用题目所给的 $h$ 和 $w$ 算出，接着便可以带入上文提出的公式中计算，即可得出 $c$ 的长度。

### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;
double a, b, h, w;
double l;
double x;
int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &h, &w);
    x = abs((h * 30 + w * 0.5) - (w * 6));
    // 求出夹角
    printf("%.10lf\n", sqrt(a * a + b * b - 2 * a * b * cos(x * M_PI / 180)));
    // 带入公式，注意保留10位小数
    return 0;
}
```