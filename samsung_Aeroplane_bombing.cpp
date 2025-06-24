#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cs=1;

int dfs(int i, int j, bool ok, vector<vector<int>>&v, int n){
     
     if(i<0){
         return 0;
     }
     if(v[i][j] == 2){
         return 0;
     }
     int ans=0;
     if(v[i][j]==1){
         ans++;
     }

     if(ok){
          vector<vector<int>>temp = v;

          for(int p=max(i-5,0); p<i; p++){
              for(int q = 0; q<5;q++){
                  if(temp[p][q]==2){
                     temp[p][q] = 0;
                  }
              }
          }

          // use kore felsi bomb; 
          int op1 = 0, op2 = 0, op3 = 0;

          if(j+1<5){
              op1 = dfs(i-1,j+1,false,temp,n);
          }
          if(j-1>=0){
              op2 = dfs(i-1,j-1,false,temp,n);
          }
          op3 = dfs(i-1,j,false,temp,n);

          int final1 = max({op1,op2,op3}) + ans;

          // use kori nai bombo;

          op1 = 0, op2 = 0, op3 = 0;

          if(j+1<5){
              op1 = dfs(i-1,j+1,true,v,n);
          }
          if(j-1>=0){
              op2 = dfs(i-1,j-1,true,v,n);
          }
          op3 = dfs(i-1,j,true,v,n);

          int final2 = max({op1,op2,op3}) + ans;
          
          return max(final1,final2); 
     }
     else{
          // use kora sesh
          int op1 = 0, op2 = 0, op3 = 0;

          if(j+1<5){
              op1 = dfs(i-1,j+1,false,v,n);
          }
          if(j-1>=0){
              op2 = dfs(i-1,j-1,false,v,n);
          }
          op3 = dfs(i-1,j,false,v,n);

          int final1 = max({op1,op2,op3}) + ans; 
          return final1;         
     }

}

void solve(){
      int n;

      scanf("%d", &n);

      vector<vector<int>>a(n+1,vector<int>(5,0));

      for(int i=0;i<n;i++){
         for(int j=0;j<5;j++){
             scanf("%d", &a[i][j]);
         }
      }

      for(int j=0;j<5;j++){
          a[n][j] = 0;
      }
      int ans = dfs(n,2,true,a,n);
      cout<<"#"<<cs++<<" "<<ans<<endl;
}

int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int t; 
     scanf("%d", &t);

     while(t--){
        solve();
     }
}