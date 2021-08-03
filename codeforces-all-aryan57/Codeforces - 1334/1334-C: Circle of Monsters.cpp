//https://codeforces.com/contest/1334/problem/C

/*
    author : Aryan Agarwal, 19CS30005, IIT KGP
*/

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;                        /*more than (10)^9*/
int PEG = 998244353; /*less than (10)^9*/ /*1 + 7*17*(2)^23*/
const double pie = 2 * acos(0.0);

typedef long long int ll;
typedef unsigned long long ull;

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define int ll
#define F(i, a, b) for (ll i = a; i <= b; i++)
#define RF(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n) F(i, 0, n - 1) \
                     cin >> a[i]
#define in1(a, n) F(i, 1, n) \
                      cin >> a[i]
#define out(a, n)            \
    F(i, 0, n - 1)           \
        cout << a[i] << " "; \
    cout << "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pfy cout << "YES"
#define pfn cout << "NO"
#define pfn1 cout << "-1" // printf negative 1
#define pf1 cout << "1"
#define nl cout << "\n"
#define gcd(a, b) __gcd((a), (b))

int binpow(int x, int y, int p) /* (x^y)%p in O(log y) */
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int mod_inverse(int n, int p) /* Returns n^(-1) mod p */ { return binpow(n, p - 2, p); }

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> vv(n);
    int sumvv=0;

    cin >> v[0].first >> v[0].second;
    F(i, 1, n - 1)
    {
        cin >> v[i].first >> v[i].second;
        vv[i] = v[i].first - v[i - 1].second;
        if (vv[i] < 0)
            vv[i] = 0;
        sumvv+=vv[i];
    }

    vv[0] = v[0].first - v[n - 1].second;
    if (vv[0] < 0)
        vv[0] = 0;

    sumvv+=vv[0];

    int min = LONG_LONG_MAX;
    
    F(i, 0, n - 1)
    {
        if (min > sumvv-vv[i]+v[i].first)
        {
            min = sumvv-vv[i]+v[i].first;
            // mini = i;
        }
    }

    cout << min;
    nl;
}

signed main()
{
    fast;

    int _t;
    cin >> _t;
    while (_t--)
    {
        solve();
    }

    return 0;
}