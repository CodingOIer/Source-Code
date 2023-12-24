## AtCoder ABC140 D 题解

### 思路分析

对于这道题，每次翻转之后的结果的中间部分的幸福的人数和原来没有任何区别，只有两边的人可能会和旁边的人产生新的幸福的人，下面是一个例子：

Before：

```
LLLRRLLRLRRLL
```

After：

```
RRRLLRRLRLLRR
```

Before 的幸福的人数为 $6$。

After 的幸福的人数依然为 $6$。

在 $K$ 次翻转中，我们只需要选取两个旁边不符的位置，翻转这一段即可得到 $2$ 个新的幸福的人数。

就算最后没有了，也可以翻转单个人来获得 $1$ 个新的幸福的人。

写模拟？不，我们再分析一下规律：

- 当 $N$ 足够大时，增加的幸福的人最多为 $2 \times K$。

- 在一组数据中，幸福的人最多为 $N - 1$。

所以，设数据中初始的幸福的人为 $answer$，则答案为：

$$
min(answer + 2 \times K, N - 1)
$$

### 代码实现

先统计出初始的幸福的人，后面直接输出 $min(answer + 2 \times K, N - 1)$。

```cpp
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define debug printf("Debug\n")
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MaxN = 1e5 + 5;
int n, k;
int answer;
char s[MaxN];
int main()
{
    scanf("%d%d", &n, &k);
    getchar();
    scanf("%s", s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            answer++;
        }
    }
    printf("%d\n", std::min(answer + 2 * k, n - 1));
    return 0;
}
```
