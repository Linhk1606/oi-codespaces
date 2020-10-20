// also poj 3974

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
typedef unsigned long long ull;

const int N = 1000005, BASE = 33;
ull lhash[N], rhash[N], pw[N];

string para;
int len;

inline bool check(int length)
{
    int half = length >> 1;
    if (length & 1)
    {
        for (int i = half + 1; i <= len - half; i++)
            if (lhash[i - 1] - lhash[i - half - 1] * pw[half] == rhash[i + 1] - rhash[i + half + 1] * pw[half])
                return true;
        return false;
    }
    else
    {
        for (int i = half; i <= len - half; i++)
            if (lhash[i] - lhash[i - half] * pw[half] == rhash[i + 1] - rhash[i + half + 1] * pw[half])
                return true;
        return false;
    }
}

inline int binary_odd(int l, int r)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid << 1 ^ 1))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

inline int binary_even(int l, int r)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid << 1))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    int cs = 1;
    pw[0] = 1;
    while (true)
    {
        cin >> para;
        if (para == "END")
            break;
        len = para.length();
        lhash[0] = rhash[len + 1] = 0;
        for (int i = 0; i < len; i++)
        {
            lhash[i + 1] = lhash[i] * BASE + para[i] - 64;
            rhash[len - i] = rhash[len - i + 1] * BASE + para[len - i - 1] - 64;
            pw[i + 1] = pw[i] * BASE;
        }
        printf("Case %d: %d\n", cs++, max(binary_odd(0, len >> 1 ^ 1) << 1 ^ 1, binary_even(0, len >> 1 ^ 1) << 1));
    }
    return 0;
}