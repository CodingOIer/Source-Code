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
const int MaxN = 1e3 + 5;
int n;
int x;
int cnt;
int top;
int head;
int tail;
int a[MaxN];
int b[MaxN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        top++;
        scanf("%d", &a[i]);
    }
    head = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == n - i + 1)
        {
            continue;
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("1");
            tail++;
            b[tail] = a[top];
            top--;
        }
        for (; head <= tail && b[head] != n - i + 1;)
        {
            printf("2");
            top++;
            a[top] = b[head];
            head++;
            cnt++;
        }
        for (; cnt;)

        {
            printf("1");
            cnt--;
            tail++;
            b[tail] = a[top];
            top--;
        }
        top++;
        a[top] = b[head];
        head++;
        printf("2");
        for (; head <= tail;)
        {
            printf("2");
            top++;
            a[top] = b[head];
            head++;
        }
        head = 1, tail = 0;
    }
    printf("\n");
    return 0;
}
