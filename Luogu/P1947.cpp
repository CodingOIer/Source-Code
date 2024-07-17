extern "C" int Seniorious(int);
extern "C" int Chtholly(int n, int c)
{
    int l, r;
    l = 1;
    r = n;
    for (; l <= r;)
    {
        int mid = (l + r) / 2;
        int re = Seniorious(mid);
        if (re == 0)
        {
            return mid;
        }
        else if (re > 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}