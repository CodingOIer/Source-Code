#include <cstdio>
#include <cstring>

class BigNumber
{
  private:
    int f;
    int len;
    char number[1005];
    void div_ten(BigNumber &__x)
    {
        BigNumber ten;
        ten = 10;
        if (__x < ten)
        {
            __x = 0;
        }
        else
        {
            __x.len--;
            for (int i = 1; i <= __x.len; i++)
            {
                __x.number[i] = __x.number[i + 1];
            }
        }
    }

  public:
    void format()
    {
        for (; (*this).len >= 1 && (*this).number[(*this).len] == 0;)
        {
            (*this).len--;
        }
        if ((*this).len == 1 && (*this).number[1] == 0)
        {
            (*this).f = 1;
        }
        if ((*this).len == 0)
        {
            (*this).f = 1;
            (*this).len = 1;
            (*this).number[1] = 0;
        }
    }
    void input()
    {
        char s[10005];
        scanf("%s", s);
        *this = s;
        (*this).format();
    }
    void output()
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
        BigNumber a, b;
        a = *this;
        b = __x;
        if (a.f == -1 && b.f == 1)
        {
            return true;
        }
        else if (a.f == 1 && b.f == -1)
        {
            return false;
        }
        else
        {
            if (a.len < b.len)
            {
                return a.f == 1 ? true : false;
            }
            else if (a.len > b.len)
            {
                return a.f == 1 ? false : true;
            }
            else
            {
                for (int i = a.len; i >= 1; i--)
                {
                    if (a.number[i] < b.number[i])
                    {
                        return a.f == 1 ? true : false;
                    }
                    else if (a.number[i] > b.number[i])
                    {
                        return a.f == 1 ? false : true;
                    }
                }
                return false;
            }
        }
    }
    bool operator>(const BigNumber __x)
    {
        BigNumber a, b;
        a = *this;
        b = __x;
        if (a.f == -1 && b.f == 1)
        {
            return false;
        }
        else if (a.f == 1 && b.f == -1)
        {
            return true;
        }
        else
        {
            if (a.len < b.len)
            {
                return a.f == 1 ? false : true;
            }
            else if (a.len > b.len)
            {
                return a.f == 1 ? true : false;
            }
            else
            {
                for (int i = a.len; i >= 1; i--)
                {
                    if (a.number[i] < b.number[i])
                    {
                        return a.f == 1 ? false : true;
                    }
                    else if (a.number[i] > b.number[i])
                    {
                        return a.f == 1 ? true : false;
                    }
                }
                return false;
            }
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
    bool operator!=(const BigNumber __x)
    {
        return !(*this == __x);
    }
    bool operator>=(const BigNumber __x)
    {
        return *this > __x || *this == __x;
    }
    bool operator<=(const BigNumber __x)
    {
        return *this < __x || *this == __x;
    }

    bool operator<(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this < t;
    }
    bool operator>(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this > t;
    }
    bool operator==(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this == t;
    }
    bool operator!=(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this != t;
    }
    bool operator>=(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this >= t;
    }
    bool operator<=(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this <= t;
    }

    bool operator<(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this < t;
    }
    bool operator>(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this > t;
    }
    bool operator==(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this == t;
    }
    bool operator!=(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this != t;
    }
    bool operator>=(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this >= t;
    }
    bool operator<=(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this <= t;
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

    void operator+=(const BigNumber __x)
    {
        *this = *this + __x;
    }
    void operator-=(const BigNumber __x)
    {
        *this = *this - __x;
    }
    void operator*=(const BigNumber __x)
    {
        *this = *this * __x;
    }
    void operator/=(const BigNumber __x)
    {
        *this = *this / __x;
    }
    void operator%=(const BigNumber __x)
    {
        *this = *this % __x;
    }

    void operator+=(const int __x)
    {
        *this = *this + __x;
    }
    void operator-=(const int __x)
    {
        *this = *this - __x;
    }
    void operator*=(const int __x)
    {
        *this = *this * __x;
    }
    void operator/=(const int __x)
    {
        *this = *this / __x;
    }
    void operator%=(const int __x)
    {
        *this = *this % __x;
    }

    void operator+=(const long long __x)
    {
        *this = *this + __x;
    }
    void operator-=(const long long __x)
    {
        *this = *this - __x;
    }
    void operator*=(const long long __x)
    {
        *this = *this * __x;
    }
    void operator/=(const long long __x)
    {
        *this = *this / __x;
    }
    void operator%=(const long long __x)
    {
        *this = *this % __x;
    }

    BigNumber operator+(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        result = 0;
        a = *this;
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
        result.format();
        return result;
    }
    BigNumber operator-(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        result = 0;
        a = *this;
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
        result.format();
        return result;
    }
    BigNumber operator*(const BigNumber __x)
    {
        BigNumber a, b;
        BigNumber result;
        result = 0;
        a = *this;
        b = __x;
        int add;
        add = 0;
        result.len = a.len + b.len;
        result.f = a.f * b.f;
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
        result.format();
        return result;
    }
    BigNumber operator/(const BigNumber __x)
    {
        int f;
        BigNumber a, b;
        BigNumber base;
        BigNumber temp;
        BigNumber result;
        base = 1;
        result = 0;
        a = *this;
        b = __x;
        f = a.f * b.f;
        a.f = 1;
        b.f = 1;
        temp = b;
        for (; a >= temp * 10;)
        {
            base *= 10;
            temp *= 10;
        }
        for (; a >= b;)
        {
            for (; a >= temp;)
            {
                a -= temp;
                result += base;
            }
            div_ten(temp);
            div_ten(base);
        }
        result.f = f;
        result.format();
        return result;
    }
    BigNumber operator%(const BigNumber __x)
    {
        return *this - *this / __x * __x;
    }

    BigNumber operator+(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this + t;
    }
    BigNumber operator-(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this - t;
    }
    BigNumber operator*(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this * t;
    }
    BigNumber operator/(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this / t;
    }
    BigNumber operator%(const int __x)
    {
        BigNumber t;
        t = __x;
        return *this % t;
    }

    BigNumber operator+(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this + t;
    }
    BigNumber operator-(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this - t;
    }
    BigNumber operator*(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this * t;
    }
    BigNumber operator/(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this / t;
    }
    BigNumber operator%(const long long __x)
    {
        BigNumber t;
        t = __x;
        return *this % t;
    }
};

int t;
int n;

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        BigNumber answer;
        answer = 1;
        for (int i = 2; i <= n; i++)
        {
            answer *= i;
        }
        answer.output();
        printf("\n");
    }
    return 0;
}