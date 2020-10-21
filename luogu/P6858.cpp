#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 998244353;

inline ull read() {
    ull s = 0, f = 1; char ch;
    while (!isdigit(ch = getchar())) (ch == '-') && (f = -f);
    for (s = ch ^ 48; isdigit(ch = getchar()); s = (s << 1) + (s << 3) + (ch ^ 48));
    return s * f;
}

inline ull qpow(ull base, ull pw)
{
    ull res = 1;
    while (pw)
    {
        if (pw & 1) res = res * base % MOD;
        base = base * base % MOD;
        pw >>= 1;
    }
    return res;
}

const ull INV2 = qpow(2, MOD - 2);

inline ull calc_fn0(ull n) { return (n * n % MOD + n * 3LL % MOD) * INV2 % MOD; }
inline ull calc_fx1(ull x) { return ((x * x % MOD + 5ULL * x % MOD) % MOD + 2ULL) * INV2 % MOD; }

int main()
{
    ull n, m;
    n = read() % MOD; m = read();
    ull fn = calc_fn0(n);
    for (ull i = 1ULL; i <= m; i++)
    {
        fn = (qpow((n + i) % MOD, MOD - 2) *
                (n * calc_fx1((n + i - 1) % MOD) % MOD
                    + i * fn % MOD) % MOD + 1) % MOD;
    }
    printf("%d\n", int(fn));
    return 0;
}