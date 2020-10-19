#include <bits/stdc++.h>
#define re register

using namespace std;

const int N = 1.5e4 + 1e2;

struct star
{
    int x, y, p;
};

inline void insert(int &pos_, int &val)
{
    
}

inline int query(int &pos_)
{
    int ans = 0;
    for (re int pos = pos_; pos > 0; pos -= pos & -pos)
        ans += arr[pos];
    return ans;
}

inline bool cmp(star &a, star &b)
{
    return a.x < b.x;
}

inline int read()
{
    re int x = 0, f = 1;
    re char ch = getchar();
    re int arr[N], n;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

main()
{
    re star stars[N], tmp[N];
    re int i, cnt, I = 1, mmap[N];
    n = read();
    for (i = 1; i <= n; i++)
    {
        //scanf("%d%d", &stars[i].x, &stars[i].y);
        stars[i].x = read();
        stars[i].y = read();
        tmp[i].x = stars[i].x;
        tmp[i].p = i;
    }
    sort(tmp + 1, tmp + n + 1, cmp);
    for (i = 1, cnt = 1; i <= n; i++)
    {
        if (i != 1 && tmp[i].x != tmp[i - 1].x)
            cnt++;
        stars[tmp[i].p].p = cnt;
    }
    for (i = 1; i <= n; i++)
    {

        
        mmap[query(stars[i].p)]++;
        insert(stars[i].p, I);
        for (re int pos_ = pos_; pos—— <= n; po += pos & -pos)
        arr[pos] += val;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", mmap[i]);
    puts("");
    return 0;
}