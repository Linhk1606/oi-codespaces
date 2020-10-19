#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
int N, K;

const int SZN = 10, SZM = 2000, SZS = 100;

int sit[SZM], gs[SZM];
long long dp[SZN][SZM][SZS];
int zt_cnt = 0;

void dfs(int gw, int zt, int x)
{
    if (x >= N)
    {
        zt_cnt++;
        sit[zt_cnt] = zt;
        gs[zt_cnt] = gw;
        return;
    }
    dfs(gw, zt, x + 1);
    dfs(gw + 1, zt + (1 << x), x + 2);
}

int main()
{
    scanf("%d%d", &N, &K);
    dfs(0, 0, 0);
    for (int i = 1; i <= zt_cnt; i++)
        dp[1][i][gs[i]] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= zt_cnt; j++)
        {
            for (int k = 1; k <= zt_cnt; k++)
            {
                if ((sit[j] & sit[k]) || ((sit[j] << 1) & sit[k]) || ((sit[k] << 1) & sit[j]))
                    continue;
                for (int l = K; l >= gs[j]; l--)
                    dp[i][j][l] += dp[i - 1][k][l - gs[j]];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= zt_cnt; i++)
        ans += dp[N][i][K];
    printf("%lld", ans);
    return 0;
}