#include <cstdio>
#include <cstring>

class BigNumber
{
  private:
    int f;
    int len;
    int number[100005];

  public:
    void print()
    {
        if (f == -1)
        {
            printf("-");
        }
        for (int i = len; i >= 1; i--)
        {
            printf("%d", number[i]);
        }
    }
    bool operator<(const BigNumber __x)
    {
        if (len > __x.len)
        {
            return f == 1 ? false : true;
        }
        else if (len < __x.len)
        {
            return f == 1 ? true : false;
        }
        else
        {
            for (int i = 1; i <= len; i++)
            {
                if (number[i] > __x.number[i])
                {
                    return f == 1 ? false : true;
                }
                else if (number[i] < __x.number[i])
                {
                    return f == 1 ? true : false;
                }
            }
            return f == 1 ? true : false;
        }
    }
    bool operator>(const BigNumber __x)
    {
        if (len > __x.len)
        {
            return f == 1 ? true : false;
        }
        else if (len < __x.len)
        {
            return f == 1 ? false : true;
        }
        else
        {
            for (int i = 1; i <= len; i++)
            {
                if (number[i] > __x.number[i])
                {
                    return f == 1 ? true : false;
                }
                else if (number[i] < __x.number[i])
                {
                    return f == 1 ? false : true;
                }
            }
            return f == 1 ? false : true;
        }
    }
    bool operator==(const BigNumber __x)
    {
        if (len != __x.len || f != __x.f)
        {
            return false;
        }
        else
        {
            for (int i = 1; i <= len; i++)
            {
                if (number[i] != __x.number[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
    void operator=(const BigNumber __x)
    {
        memset(number, 0, sizeof(number));
        f = __x.f;
        len = __x.len;
        for (int i = 1; i <= len; i++)
        {
            number[i] = __x.number[i];
        }
    }
    void operator=(const int __x)
    {
        memset(number, 0, sizeof(number));
        if (__x == 0)
        {
            f = 1;
            len = 1;
            number[1] = 0;
        }
        else
        {
            int __y;
            if (__x < 0)
            {
                f = -1;
                __y = -__x;
            }
            else
            {
                f = 1;
                __y = __x;
            }
            len = 0;
            for (; __y != 0;)
            {
                len++;
                number[len] = __y % 10;
                __y /= 10;
            }
        }
    }
    void operator=(const long long __x)
    {
        memset(number, 0, sizeof(number));
        if (__x == 0)
        {
            f = 1;
            len = 1;
            number[1] = 0;
        }
        else
        {
            long long __y;
            if (__x < 0)
            {
                f = -1;
                __y = -__x;
            }
            else
            {
                f = 1;
                __y = __x;
            }
            len = 0;
            for (; __y != 0;)
            {
                len++;
                number[len] = __y % 10;
                __y /= 10;
            }
        }
    }
    void operator=(const char s[])
    {
        memset(number, 0, sizeof(number));
        if (s[0] == '-')
        {
            f = -1;
            len = strlen(s) - 1;
            for (int i = 1; i <= len; i++)
            {
                number[i] = s[len - i + 1] - '0';
            }
        }
        else
        {
            f = 1;
            len = strlen(s);
            for (int i = 1; i <= len; i++)
            {
                number[i] = s[len - i] - '0';
            }
        }
    }
    BigNumber operator+(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        a = 0;
        result = 0;
        a.f = f;
        a.len = len;
        for (int i = 1; i <= len; i++)
        {
            a.number[i] = number[i];
        }
        b = __x;
        int add;
        add = 0;
        result.len = a.len > b.len ? a.len : b.len;
        if (a.f == -1 && b.f == -1)
        {
            result.f = -1;
        }
        if (a.f == -1 && b.f == 1)
        {
            a.f = 1;
            return b - a;
        }
        if (a.f == 1 && b.f == -1)
        {
            b.f = 1;
            return a - b;
        }
        if (a.f == 1 && b.f == 1)
        {
            result.f = 1;
        }
        for (int i = 1; i <= result.len; i++)
        {
            result.number[i] = a.number[i] + b.number[i] + add;
            add = 0;
            for (; result.number[i] >= 10;)
            {
                result.number[i] -= 10;
                add++;
            }
        }
        if (add != 0)
        {
            result.len++;
            result.number[result.len] = add;
        }
        return result;
    }
    BigNumber operator-(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        a = 0;
        result = 0;
        a.f = f;
        a.len = len;
        for (int i = 1; i <= len; i++)
        {
            a.number[i] = number[i];
        }
        b = __x;
        int add;
        add = 0;
        ;
        result.len = a.len > b.len ? a.len : b.len;
        if (a.f == -1 && b.f == -1)
        {
            b.f = 1;
            return a + b;
        }
        if (a.f == 1 && b.f == -1)
        {
            b.f = 1;
            return a + b;
        }
        if (a.f == -1 && b.f == 1)
        {
            a.f = 1;
            result = a + b;
            result.f = -1;
            return result;
        }
        if (a.f == 1 && b.f == 1)
        {
            result.f = 1;
        }
        if (a < b)
        {
            result.f = -1;
            BigNumber c;
            c = a;
            a = b;
            b = c;
        }
        for (int i = 1; i <= result.len; i++)
        {
            result.number[i] = a.number[i] - b.number[i] - add;
            add = 0;
            for (; result.number[i] < 0;)
            {
                result.number[i] += 10;
                add++;
            }
        }
        if (add != 0)
        {
            result.len++;
            result.number[result.len] = -add;
        }
        for (; result.number[result.len] == 0 && result.len >= 2;)
        {
            result.len--;
        }
        if (result.len == 1 && result.number[len] == 0)
        {
            result.f = 1;
        }
        return result;
    }
    BigNumber operator*(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        a = 0;
        result = 0;
        a.f = f;
        a.len = len;
        for (int i = 1; i <= len; i++)
        {
            a.number[i] = number[i];
        }
        b = __x;
        int add;
        add = 0;
        result.len = a.len + b.len;
        if (a.f == -1 && b.f == -1)
        {
            result.f = -1;
        }
        if (a.f == -1 && b.f == 1)
        {
            a.f = 1;
            return b - a;
        }
        if (a.f == 1 && b.f == -1)
        {
            b.f = 1;
            return a - b;
        }
        if (a.f == 1 && b.f == 1)
        {
            result.f = 1;
        }
        for (int i = 1; i <= a.len; i++)
        {
            add = 0;
            for (int j = 1; j <= b.len; j++)
            {
                result.number[i + j - 1] += a.number[i] * b.number[j] + add;
                add = 0;
                for (; result.number[i + j - 1] >= 10;)
                {
                    result.number[i + j - 1] -= 10;
                    add++;
                }
            }
            result.number[i + b.len] += add;
        }
        for (; result.number[result.len] == 0;)
        {
            result.len--;
        }
        return result;
    }
};

const int MaxN = 1e5 + 5;

char a[MaxN];
char b[MaxN];

BigNumber x;
BigNumber y;

int main()
{
    scanf("%s", a);
    scanf("%s", b);

    x = a;
    y = b;

    (x + y).print();

    return 0;
}