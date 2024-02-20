#include <cstdio>
#include <queue>
#include <unordered_map>
constexpr int MaxN = 1e4 + 5;
class node
{
  public:
    int key;
    int add;
    int time;
    friend bool operator<(const node &__x, const node &__y)
    {
        return __x.time > __y.time || (__x.time == __y.time && __x.key > __y.key);
    }
};
int k;
char s[MaxN];
std::priority_queue<node> queue;
int main()
{
    for (;;)
    {
        scanf("%[^\n]s", s);
        getchar();
        if (s[0] == '#')
        {
            break;
        }
        sprintf(s, "%s", s + 9);
        int x, y;
        x = 0;
        y = 0;
        for (;;)
        {
            if (s[0] == ' ')
            {
                break;
            }
            x *= 10;
            x += s[0] - '0';
            sprintf(s, "%s", s + 1);
        }
        sprintf(s, "%s", s + 1);
        for (;;)
        {
            if (s[0] == ' ' || s[0] == '\0')
            {
                break;
            }
            y *= 10;
            y += s[0] - '0';
            sprintf(s, "%s", s + 1);
        }
        node temp;
        temp.key = x;
        temp.add = y;
        temp.time = y;
        queue.push(temp);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        node temp = queue.top();
        queue.pop();
        printf("%d\n", temp.key);
        temp.time += temp.add;
        queue.push(temp);
    }
    return 0;
}