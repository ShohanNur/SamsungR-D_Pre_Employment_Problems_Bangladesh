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
     ll a,b,c,x;
     cin>>a>>b>>c>>x;


     ll low = 1;
     ll high = 1000000;
     ll ans=-1;
     while(low <= high){

     	   ll mid = (low+high)/2;

     	   ll xx = a * mid + (b * mid * log2(mid)) + (c * mid * mid * mid);

     	   if(xx >= x){
     	   	  ans = mid;
     	   	  high = mid - 1;
     	   }
     	   else{
     	   	  low = mid + 1;
     	   }
     }
     cout<<ans<<endl;
}
int32_t main()
{
   fastio
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}
/*
1 2 3 212
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lg(long long N)
{
    ll value = 0;
    while (N >= 2.71828)
    {
        value++;
        N /= 2.71828;
    }
    return value;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, x;
        cin >> a >> b >> c >> x;
        ll ans = 0;
        for (ll i = 1; i <= 10000000; i++)
        {
            if (x % i == 0)
            {
                // cout << i << endl;
                ll val = a + (b * log2(i)) + (c * i * i);
                if (val == x / i)
                {
                    ans = i;
                    break;
                }
            }
        }
        // cout << lg(6285978519716) << endl;
        cout << ans << endl;
    }
    return 0;
}
*/