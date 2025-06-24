#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      500001
#define endl     "\n"
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define eps      1e-6
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll ans = 0;

    while (n > 3) {
        ll option1 = a[1] + 2 * a[2] + a[n];       // send fastest & second fastest, return fastest, send slowest two, return second fastest
        ll option2 = 2 * a[1] + a[n] + a[n - 1];   // send fastest with each of the two slowest
        ans += min(option1, option2);
        n -= 2;
    }

    if (n == 3)
        ans += a[1] + a[2] + a[3];
    else if (n == 2)
        ans += a[2];
    else if (n == 1)
        ans += a[1];

    cout << ans << endl;
}

int32_t main()
{
    fastio
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
