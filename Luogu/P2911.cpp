#include <cstdio>
#include <map>
int x, y, z;
std::map<int, int> map;
int main()
{
    scanf("%d%d%d", &x, &y, &z);
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            for (int k = 1; k <= z; k++)
            {
                map[i + j + k]++;
            }
        }
    }
    int best = 0;
    int answer = 0;
    for (auto k : map)
    {
        if (k.second > best)
        {
            answer = k.first;
            best = k.second;
        }
    }
    printf("%d\n", answer);
    return 0;
}