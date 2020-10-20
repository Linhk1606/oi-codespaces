#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int S = 1005, BASE1 = 233, BASE2 = 133331;

ull mmap[S][S], hash1_1[S][S], hash1_2[S][S], hash2_1[S][S], hash2_2[S][S], pw1[S], pw2[S];
int n, m;

inline bool check(int siz)
{
    for (int i = 1; i <= n - siz + 1; i++)
        for (int j = 1; j <= m - siz + 1; j++)
            if (hash1_2[i + siz - 1][j + siz - 1] - hash1_2[i + siz - 1][j - 1] * pw1[siz] - hash1_2[i - 1][j + siz - 1] * pw2[siz] + hash1_2[i - 1][j - 1] * pw1[siz] * pw2[siz]
             == hash2_2[i][j] - hash2_2[i][j + siz] * pw1[siz] - hash1_2[i + siz][j] * pw2[siz] + hash1_2[i + siz][j + siz] * pw1[siz] * pw2[siz])
                return true;
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mmap[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            hash1_1[i][j] = hash1_1[i][j - 1] * BASE1 + mmap[i][j];
            hash1_2[i][j] = hash1_2[i - 1][j] * BASE2 + hash1_1[i][j];
            hash2_1[n - i + 1][n - j + 1] = hash2_1[n - i + 1][n - j + 2] * BASE1 + mmap[n - i + 1][n - j + 1];
            hash2_2[n - i + 1][n - j + 1] = hash2_1[n - i + 2][n - j + 1] * BASE2 + hash2_1[n - i + 1][n - j + 1];
        }
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n || i <= m; i++)
        pw1[i] = pw1[i - 1] * BASE1, pw2[i] = pw2[i - 1] * BASE2;
    int l = 0, r = min(m, n) + 1, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}