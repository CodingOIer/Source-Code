#include <cstdio>
#include <unordered_map>
#include <vector>
constexpr int MaxN = 2e6 + 5;
namespace std
{
template <typename type> class stack
{
    int top = 0;
    std::vector<type> stk;
    std::vector<unsigned long long> ha;

  public:
    stack()
    {
        stk.resize(5);
        ha.resize(5);
        ha[0] = 1e18 + 31;
    }
    bool empty()
    {
        return top == 0;
    }
    void push(const type &x)
    {
        stk.resize(top + 5);
        ha.resize(top + 5);
        top++;
        stk[top] = x;
        ha[top] = ha[top - 1] * 100511 + stk[top] * 100501;
    }
    void pop()
    {
        top--;
    }
    type front()
    {
        return stk[top];
    }
    unsigned int size()
    {
        return top;
    }
    unsigned long long hash()
    {
        return ha[top];
    }
};
} // namespace std
int n;
char s[MaxN];
std::stack<char> stack;
std::unordered_map<unsigned long long, int> map;
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    map[stack.hash()]++;
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!stack.empty() && stack.front() == s[i])
        {
            stack.pop();
        }
        else
        {
            stack.push(s[i]);
        }
        answer += map[stack.hash()];
        map[stack.hash()]++;
    }
    printf("%lld\n", answer);
    return 0;
}