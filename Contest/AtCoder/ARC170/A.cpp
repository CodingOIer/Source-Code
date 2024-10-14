#include <cstdio>
#include <vector>
constexpr int MaxN = 2e5 + 5;
int n;
int cnt;
char s[MaxN];
char t[MaxN];
std::vector<int> A;
std::vector<int> B;
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B' && t[i] == 'A')
        {
            A.push_back(i);
        }
        else if (s[i] == 'A' && t[i] == 'B')
        {
            B.push_back(i);
        }
    }
    if (A.empty() && B.empty())
    {
        printf("0\n");
        return 0;
    }
    if (A.empty())
    {
        bool accept = false;
        for (int i = 0; i < B[0]; i++)
        {
            if (s[i] == 'A' && t[i] == 'A')
            {
                accept = true;
                break;
            }
        }
        if (accept)
        {
            printf("%d\n", (int)(B.size()));
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    if (B.empty())
    {
        bool accept = false;
        for (int i = A[A.size() - 1] + 1; i < n; i++)
        {
            if (s[i] == 'B' && t[i] == 'B')
            {
                accept = true;
                break;
            }
        }
        if (accept)
        {
            printf("%d\n", (int)(A.size()));
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }
    int accept = false;
    for (int i = 0; i < B[0]; i++)
    {
        if (s[i] == 'A' && t[i] == 'A')
        {
            accept = true;
            break;
        }
    }
    if (B[0] < A[0] && !accept)
    {
        printf("-1\n");
        return 0;
    }
    accept = false;
    for (int i = A[A.size() - 1]; i < n; i++)
    {
        if (s[i] == 'B' && t[i] == 'B')
        {
            accept = true;
            break;
        }
    }
    if (A[A.size() - 1] > B[B.size() - 1] && !accept)
    {
        printf("-1\n");
        return 0;
    }
    cnt = A.size() + B.size();
    if (A.size() <= B.size())
    {
        int l, r;
        l = 0;
        r = 0;
        for (; l < (int)(A.size());)
        {
            for (; r < (int)(B.size()) && B[r] < A[l];)
            {
                r++;
            }
            if (r < (int)(B.size()) && B[r] > A[l])
            {
                cnt--;
            }
            l++;
        }
    }
    else
    {
        int l, r;
        l = 0;
        r = 0;
        for (; l < (int)(B.size());)
        {
            for (; r < (int)(A.size()) && B[l] > A[r];)
            {
                r++;
            }
            if (r < (int)(A.size()) && B[l] < A[r])
            {
                cnt--;
            }
            l++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}