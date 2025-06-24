#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <climits>
using namespace std;


void solve(){
     int n;
     cin>>n;

     vector<vector<int>>a(n,vector<int>(n));

     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>a[i][j];
         }
     }

     int dp[(1<<15)][15] = {};

     for(int mask=0; mask<(1<<n); mask++){
          for(int i=0;i<n;i++){
              dp[mask][i] = INT_MAX;
          }
     }  
     dp[1][0] = 0; 

     for(int mask=0; mask<(1<<n); mask++){
         for(int u=0; u<n; u++){
              if(!(mask & (1<<u))){
                 continue;
              }
              for(int v=0; v<n; v++){
                   if(mask & 1<<n){
                       continue;
                   }

                   if(dp[mask][u]!=INT_MAX){

                        int newmask = mask|(1<<v);
                        dp[newmask][v] = min(dp[newmask][v], dp[mask][u]+a[u][v]);
                   }
              }
         }
     }

     int ans=INT_MAX;

     for(int i=0;i<n;i++){
           if(dp[(1<<n)-1][i]!=INT_MAX){
               ans = min(ans, dp[(1<<n)-1][i] + a[i][0]);
           }
     }
     if(ans==INT_MAX){
          cout<<"Impossible\n";
     }
     else{
          cout<<-1<<endl;
     }
}
int main(){

     int t; cin>>t;
     while(t--){
         solve();
     }
}


