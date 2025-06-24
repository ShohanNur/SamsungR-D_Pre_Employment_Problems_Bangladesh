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



int n;
vector<int>graph[100];
int color[101];
int vis[101];


int dfs(int x, int col){

	  vis[x] = 1;
	  color[x] = col;
	  for(auto i:graph[x]){
	  	   if(!vis[i]){
	  	   	   if(dfs(i,col^1)==0){
	  	   	   	  return 0;
	  	   	   }
	  	   }
	  	   else{
	  	   	   if(color[i]==color[x]){
	  	   	   	  return 0;
	  	   	   }
	  	   }
	  }
	  return 1; 
}
void solve()
{
   int n;
   cin>>n;

   int a[100][100];
   memset(vis,0,sizeof vis);
   memset(color,0,sizeof color);
   for(int i=0;i<n;i++){
   	  for(int j=0;j<n;j++){
   	  	  cin>>a[i][j];
   	  	  if(a[i][j]==1){
   	  	  	 graph[i].pb(j);
   	  	  }
   	  }
   }

   bool ok = 0;

   for(int i=0;i<n;i++){
   	  if(!vis[i]){
   	  	  if(dfs(i,0)==0){
   	  	  	  ok  = 1;
   	  	  	  break;
   	  	  }
   	  }
   }
   if(ok){
   	  cout<<"-1\n"; return;
   }

   for(int i=0;i<n;i++){
   	   if(color[i]==0){
   	   	  cout<<i<<" ";
   	   }
   }
   cout<<endl;


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
