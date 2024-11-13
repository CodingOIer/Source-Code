#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
const int MaxN = 1e2 + 5;
class Type // 类型
{
  public:
    long long size;                       // 类型大小
    long long align;                      // 内存对齐大小
    std::string name;                     // 类型名称
    std::vector<std::string> member_type; // 类型列表
    std::vector<std::string> member_name; // 类型名称
    void clear()                          // 清空
    {
        size = 0;
        align = 0;
        name.clear();
        member_type.clear();
        member_name.clear();
    }
};
std::map<std::string, Type> type_list; // 保存类型信息
class Element
{
  public:
    std::string name;     // 元素名称
    Type element_type;    // 元素类型
    long long start_addr; // 元素起始地址
    void clear()          // 清空
    {
        name.clear();
        element_type.clear();
        start_addr = 0;
    }
};
std::vector<Element> element_list;                              // 保存元素信息
std::map<std::string, Element *> from_name_to_element;          // 名称到元素的映射
long long addr_pos;                                             // 目前分配到的地址
std::map<std::pair<long long, long long>, Element *> addr_list; // 地址映射表
void init()                                                     // 初始化基本类型
{
    type_list["int"].size = 1;
    type_list["int"].align = 1;
    type_list["int"].name = "byte";
    type_list["int"].size = 2;
    type_list["int"].align = 2;
    type_list["int"].name = "short";
    type_list["int"].size = 4;
    type_list["int"].align = 4;
    type_list["int"].name = "int";
    type_list["int"].size = 8;
    type_list["int"].align = 8;
    type_list["int"].name = "long";
}
void createType(std::string name, int cnt)
{
    type_list[name].clear();
    char type_input[15], name_input[15];
    for (int i = 1; i <= cnt; i++)
    {
        scanf("%s %s", type_input, name_input);
        type_list[name].member_type.push_back(type_input);
        type_list[name].member_name.push_back(name_input);
        type_list[name].align = std::max(type_list[name].align, type_list[type_input].align);
    }
    type_list[name].size = type_list[name].align * cnt;
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        }
    }
    return 0;
}