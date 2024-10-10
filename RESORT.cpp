/*
Author: chikien2009
*/
#include <bits/stdc++.h>

using namespace std;

inline void setup()
{
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long n, m, p, q, b, a, mthan, lthan, eq, mid, res = 0;
long long x[2001][2001], y[2001][2001];

int main()
{
    setup();

    cin >> n >> m >> p >> q >> b;
    mid = (p * q - 1) >> 1;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = 1; j <= m; ++j)
        {
            cin >> a;
            x[i][j] = (a < b) - (a > b) + x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1];
            y[i][j] = (a == b) + y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    for (long long i = p; i <= n; ++i)
    {
        for (long long j = q; j <= m; ++j)
        {
            lthan = x[i][j] - x[i - p][j] - x[i][j - q] + x[i - p][j - q];
            eq = y[i][j] - y[i - p][j] - y[i][j - q] + y[i - p][j - q];
            if (lthan >= 0)
            {
                res += (lthan < eq);
            }
            else
            {
                res += (-lthan <= eq);
            }
        }
    }
    cout << res;
    return 0;
}
