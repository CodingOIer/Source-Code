#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
int main()
{
    // 关闭流同步，使cin和cout可以同时使用
    std::ios_base::sync_with_stdio(false);
    // 读取输入
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> o(n), v;
    for (int i = 0; i < n; i++)
        std::cin >> o[i];
    // 遍历输入的m个询问
    for (int i = 0; i < m; i++)
    {
        // 读取询问的参数
        long long l, r, k;
        std::cin >> l >> r >> k;
        // 将o中l-1到r-1的元素赋值给v
        v.assign(o.begin() + l - 1, o.begin() + r);
        // 对v进行排序，并将第k个元素赋值给ans
        std::nth_element(v.begin(), v.begin() + k - 1, v.end());
        std::cout << v[k - 1] << std::endl;
    }
    return 0;
}