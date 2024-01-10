## Code Formula 2014 本選 F 100個の円

### 思路分析

在一个 $1500 \times 1500$ 的矩阵中，要你填入 $r = 1, 2, 3 \dots 100$ 的 $100$ 个圆。求一种合法的填入方式使填入的圆**可以相切但不能重叠**。

我们发现，$1500 \times 1500$ 的矩阵范围远远大于最大的直径 $l = 200$， 所以我们可以将其看为一个 $l \times l$ 的正方形。

只考虑只填一行的情况：对于每一个正方形，将其紧挨在上一个正方形旁边，代码如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/dl28pruw.png)

但是，按照此方式得到的结果最大的长度为 $2 + 4 + 6 + \dots + 200 = 10100$ 超出了题目的限制。此时，当坐标超出 $1500 \times 1500$ 的矩阵范围时便开启下一行，代码如下：

![](https://cdn.luogu.com.cn/upload/image_hosting/dy3w5wmx.png)

### 代码实现

![](https://cdn.luogu.com.cn/upload/image_hosting/h3br8elh.png)