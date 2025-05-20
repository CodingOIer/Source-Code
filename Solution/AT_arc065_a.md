## [ABC049C] 白昼夢 题解

### 思路分析

考虑使用正则表达式匹配。

这里先给出本题的正则表达式，再来讲解。

```regex
^(dream(er)?|erase(r)?)*$
```

首先，开头的 `^` 和结尾的 `$` 指定了从字符串开头开始匹配，匹配到结尾。

`(dream(er)?|erase(r)?)*`

末尾的 `*` 表示前面一个元素（`(dream(er)?|erase(r)?)`）可以匹配任意多个，即 $0$ 到无穷个。

括号中的 `|` 表示其隔开的元素可以任意匹配其中的一个。

如 `(ab|cd|ef)` 可以匹配 `ab` / `cd` / `ed`。

对于 `dream(er)?`，`?` 表示其前面的元素（`er`）可以匹配 $0 \sim 1$ 个，即表示匹配 `dream` 或 `dreamer`。

`erase(r)?` 同理，表示可以匹配 `erase` / `eraser`。

整个正则表达式的意思即为：

> 从字符串开头开始，匹配任意多个 `dream` 或 `dreamer` 或 `erase` 或 `eraser`，直到结尾。

非常优雅。

但考虑下面的字符串：

```plain
dreamerase
dreamererase
```

他们的分词分别为

```plain
dream|erase
dreamer|erase
```

第一个的第一次需要匹配 `dream`，但是第二个第第一个需要匹配 `dreamer`，这怎么办呢。

不用管，正则表达式会使用称之为 **回溯机制** 的方式尝试找到最长匹配，在限定了从头开始到结尾的情况下，即为尝试完全匹配。

至此，`^(dream(er)?|erase(r)?)*$` 便可匹配本题的合法字符串。

### 相关定义

**警告：C++ 实现的正则表达式引擎性能不高，视表达式复杂程度会比其他语言慢 $5 \sim 10$ 倍，正则表达式效率本身也并不是很高，在大量操作时需要注意性能问题。**

自 C++11 起，正则表达式相关函数与类定义在 `<regex>` 头文件中，万能头文件亦包含此头文件。（NOI 系列竞赛可以使用正则表达式）

`std::regex` 类，即定义一个名为 `reg` 的正则表达式类，可以传入构造参数 `(RegexExpression)` 以字符串形式提供正则表达式。

`std::regex_match(String, Regex) -> bool`，在 `String` 尝试匹配 `Regex`，`Regex` 为前文定义的正则表达式类。

本题暂时只用到了这两个定义，如想了解更多可以在 CppReference 上查看。

<https://zh.cppreference.com/w/cpp/header/regex>

### 代码实现

非常简短。

```cpp
#include <cstdio>
#include <regex>
constexpr int MaxN = 1e5 + 5;
char s[MaxN];
int main()
{
    scanf("%s", s);
    printf("%s\n", std::regex_match(s, std::regex("^(dream(er)?|erase(r)?)?*$")) ? "YES" : "NO");
    return 0;
}

```