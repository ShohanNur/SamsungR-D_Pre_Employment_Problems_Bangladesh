#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>

#define   s   second
#define   f   first
using namespace std;
typedef long long ll;

int cs=1;

void solve(){

	 int n,m;
	 cin>>n>>m;

	 int s1,s2,d1,d2;
	 cin>>s1>>s2>>d1>>d2; 

	 int vis[50][50] = {};
	 int dis[50][50] = {};

	 memset(dis,INT_MIN,sizeof(dis));

	 queue<pair<pair<int,int>,int>>q; 
     int dx[] = {-2,-2,-1,-1,1,1,2,2};
     int dy[] = {-1,1,-2,2,-2,2,-1,1};
	 q.push({{s1,s2},0}); 
	 vis[s1][s2]=1; 
     int ans=-1;
	 while(!q.empty()){
	 	  auto it = q.front();
	 	  q.pop();
	 	  int x = it.f.f;
	 	  int y = it.f.s;
	 	  int d = it.s;
          if(x == d1 and y == d2){
          	  ans = d;
          	  break; 
          }
	 	  for(int i=0;i<8;i++){
	 	  	  int nx = x+dx[i];
	 	  	  int ny = y+dy[i];
              
              if(nx>=1 and nx<=n and ny>=1 and ny<=m and !vis[nx][ny]){
              	   vis[nx][ny] = 1;
              	   q.push({{nx,ny},d+1});
              }

	 	  }
	 }
	 cout<<"Case #" <<cs++<<" "<<ans<<endl;
}
int main(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);

	  int t; cin>>t;
	  while(t--){
	  	 solve();
	  }
}