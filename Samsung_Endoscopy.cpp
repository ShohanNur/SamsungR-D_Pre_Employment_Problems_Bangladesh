#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<string>

#define  f   first
#define  s   second
#define  pb  push_back
#define  endl "\n"

typedef long long ll;
using namespace std;


map<int, vector<int>> mp = {
    {1, {0,1,2,3}},
    {2, {0,2}},
    {3, {1,3}},
    {4, {0,1}},
    {5, {1,2}},
    {6, {2,3}},
    {7, {3,0}}
};

int ulta(int x){
     if(x==1){
         return 3;
     }
     if(x==3){
         return 1; 
     }
     if(x==2){
         return 0;
     }
    return 2;
}
// up right down left
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void solve(){
     
    int n,m,r,c,l;
    cin>>n>>m>>r>>c>>l; 
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
               cin>>grid[i][j];
         }
    }
    queue<pair<pair<int,int>,int>>q;
    q.push({{r,c},1});
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    vis[r][c] = 1;
    int cnt=1;
    while(!q.empty()){
          auto it = q.front();
          q.pop();
          int x = it.f.f;
          int y = it.f.s;
          int d = it.s;
          if(d>=l){
               break;
          } 
          int type = grid[x][y];
          
          for(auto i:mp[type]){
                 
                int nx = x+dx[i];
                int ny = y+dy[i]; 
                
                if(nx<0 or nx>=n or ny<0 or ny>=m){
                     continue;
                }
                if(vis[nx][ny] or grid[nx][ny]==0){
                     continue; 
                }
                int nextType = grid[nx][ny];
                int opp = ulta(i);
              
                if(find(mp[nextType].begin(),mp[nextType].end(),opp) != mp[nextType].end()){
                      vis[nx][ny] = 1;
                      q.push({{nx,ny},d+1});
                      cnt++;
                }
           } 
       }
    cout<<cnt<<endl;
 }
                             
         
    

int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}
