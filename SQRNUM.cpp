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

int n, odd = 0, even = 0, a;
bool stat[1000001];

int main()
{
    setup();

    cin >> n;
    while (n--)
    {
        cin >> a;
        for (int i = 2; i * i <= a; i += 1 + (i & 1))
        {
            odd -= (stat[i]);
            even -= !(stat[i]);
            while (a % i == 0)
            {
                a /= i;
                stat[i] ^= 1;
            }
            odd += (stat[i]);
            even += !(stat[i]);
        }
        if (1 < a)
        {
            odd -= (stat[a]);
            even -= !(stat[a]);
            stat[a] ^= 1;
            odd += (stat[a]);
            even += !(stat[a]);
        }
        cout << (odd == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
