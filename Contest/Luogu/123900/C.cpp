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
const int MaxM = 15;

class str
{
  public:
    std::string s;
    int cnt;
};

int n;
int last;

char s[MaxM];
char op[MaxM];

std::string last_1;
std::string last_2;

std::map<std::string, int> cnt;
std::map<std::string, int> have;
std::map<std::string, int> playing;

std::queue<str> queue;

void start()
{
    if (last != 0)
    {
        if (last >= 1)
        {
            have[std::string(last_1)] = 1;
            str tmp;
            tmp.s = std::string(last_1);
            tmp.cnt = cnt[std::string(last_1)];
            playing[std::string(last_1)] = 0;
            queue.push(tmp);
        }
        if (last >= 2)
        {
            have[std::string(last_2)] = 1;
            str tmp;
            tmp.s = std::string(last_2);
            tmp.cnt = cnt[std::string(last_2)];
            playing[std::string(last_2)] = 0;
            queue.push(tmp);
        }
    }
    int get;
    get = 0;
    last = 0;
    for (;;)
    {
        if (get == 2 || queue.empty())
        {
            break;
        }
        if (queue.front().cnt == cnt[std::string(queue.front().s)])
        {
            get++;
            cnt[std::string(queue.front().s)]++;
            have[std::string(queue.front().s)] = 0;
            playing[std::string(queue.front().s)] = 1;
            last++;
            if (last == 1)
            {
                last_1 = std::string(queue.front().s);
            }
            if (last == 2)
            {
                last_2 = std::string(queue.front().s);
            }
            printf("%s ", queue.front().s.c_str());
        }
        queue.pop();
    }
    if (get == 0)
    {
        printf("Error\n");
    }
    else
    {
        printf("\n");
    }
}

void arrive()
{
    char name[MaxM];
    // getchar();
    scanf("%s", name);
    // getchar();
    if (have[std::string(name)] == 1 || playing[std::string(name)] == 1)
    {
        printf("Error\n");
        return;
    }
    have[std::string(name)] = 1;
    str tmp;
    tmp.s = std::string(name);
    tmp.cnt = cnt[std::string(name)];
    queue.push(tmp);
    printf("OK\n");
}

void leave()
{
    char name[MaxM];
    // getchar();
    scanf("%s", name);
    // getchar();
    if (have[std::string(name)] == 0 || playing[std::string(name)] == 1)
    {
        printf("Error\n");
        return;
    }
    cnt[std::string(name)]++;
    have[std::string(name)] = 0;
    printf("OK\n");
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", op);
        if (!strcmp(op, "start"))
        {
            start();
        }
        else if (!strcmp(op, "arrive"))
        {
            arrive();
        }
        else if (!strcmp(op, "leave"))
        {
            leave();
        }
    }
    return 0;
}