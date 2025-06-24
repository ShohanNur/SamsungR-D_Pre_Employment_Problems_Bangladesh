#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
#include<queue>
using namespace std;

#define f first
#define s second
#define pb push_back


using namespace std;

int tc=1;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void solve(){
    
    int n,m;
    cin>>n>>m;
	vector<vector<int>>v(n,vector<int>(m));

	for(int i=0;i<n;i++){
		 for(int j=0;j<m;j++){
		 	 cin>>v[i][j];
		 }
	}
    
    int sx,sy;
    cin>>sx>>sy;
	queue<pair<pair<int,int>,int>>q;
    sx--;
    sy--;
	q.push({{sx,sy},1});

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
    vis[sx][sy] = 1;
    dis[sx][sy] = 1;

    while(!q.empty()){
    	  auto it = q.front();
    	  q.pop();

    	  int x = it.f.f;
    	  int y = it.f.s;
    	  int d = it.s;

          for(int i=0;i<4;i++){
          	   int nx = x + dx[i];
          	   int ny = y + dy[i];
               
               if(nx>=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny] and v[nx][ny]==1){
                     vis[nx][ny] = 1;
                     if(dis[x][y]+1 < dis[nx][ny]){
                     	dis[nx][ny] = dis[x][y]+1;
                     }
                     q.push({{nx,ny},dis[nx][ny]});
               } 
          }
    }

    int mx = 0;
    for(int i=0;i<n;i++){
    	 for(int j=0;j<m;j++){
    	 	if(dis[i][j]!=INT_MAX){
    	   	  mx = max(mx,dis[i][j]);
    	    }
    	 }
    }
    cout<<"Case #"<<tc++<<endl;
    cout<<mx<<endl;
}

int main(){
	 int t;
	 t=1; 
	 cin>>t;
	 while(t--){
	 	 solve();
	 }
}