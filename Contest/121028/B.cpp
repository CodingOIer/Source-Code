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
int s_x, s_y;
int c_x, c_y;
int m_x, m_y;
int move_x[] = {2, 2, 1, 1, -2, -2, -1, -1};
int move_y[] = {-1, 1, -2, 2, -1, 1, -2, 2};
int main()
{
    scanf("%d%d", &s_x, &s_y);
    scanf("%d%d", &c_x, &c_y);
    scanf("%d%d", &m_x, &m_y);
    for (int i = 0; i < 8; i++)
    {
        bool king, car;
        king = false;
        car = false;
        int now_x, now_y;
        now_x = m_x + move_x[i];
        now_y = m_y + move_y[i];
        if (!(1 <= now_x && now_x <= 10 && 1 <= now_y && now_y <= 9))
        {
            continue;
        }
        for (int j = 0; j < 8; j++)
        {
            if (now_x + move_x[j] == s_x && now_y + move_y[j] == s_y)
            {
                king = true;
            }
            if (now_x + move_x[j] == c_x && now_y + move_y[j] == c_y)
            {
                car = true;
            }
        }
        if (king && car)
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}