#include <algorithm>
#include <cstdio>
#include <map>
int n;
std::map<int, int> map;
int main()
{
    scanf("%d", &n);
    int answer = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (map.count(x) != 0)
        {
            answer = std::min(answer, i - map[x] + 1);
        }
        map[x] = i;
    }
    printf("%d\n", answer == 0x7f7f7f7f ? -1 : answer);
    return 0;
}
