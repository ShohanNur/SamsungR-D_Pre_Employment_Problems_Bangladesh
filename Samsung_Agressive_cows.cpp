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


ll ok(vector<ll>&v, ll x, ll k){

	   ll l = 0; 
       ll cnt=1;
	   for(int i=1;i<v.size();i++){
	   	    if((v[i] - v[l]) >=x){
                  l = i;
                  cnt++;
                  if(cnt==k){
                     return 1;  
                  }
	   	    }
	   }
	   return 0;
}

void solve()
{
    ll n,k; cin>>n>>k;
    vector<ll>a(n);
    ll mx = 0;
    for(int i=0;i<n;i++){
    	 cin>>a[i];
    	 mx = max(mx,a[i]);
    }


    ll low = 0;
    ll high = mx;
    ll ans=-1;
    while(low <= high){

    	   ll mid = (high+low)/2;

    	   if(ok(a,mid,k)){
    	   	  ans = mid;
    	   	  low = mid+1;
    	   }
    	   else{
    	   	  high = mid-1;
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
