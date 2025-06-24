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

using namespace std;
typedef long long ll;

void solve(){
     ll n;
     scanf("%lld", &n);

     vector<ll>a(n+2);
     a[0] = 1;

     for(ll i=1;i<=n;i++){
          scanf("%lld", &a[i]);
     }
     a[n+1] = 1;

     ll dp[20][20]={};

     for(int len=1;len<=n;len++){
         for(int i=1;i<=n-len+1;i++){
             ll j = i+len-1;
             for(int k=i;k<=j;k++){

                ll left = dp[i][k-1];
                ll right = dp[k+1][j];
                ll gain;
                if(len==n){
                    gain = a[k];
                }
                else{
                    gain = a[i-1]*a[j+1];
                }
                dp[i][j] = max(dp[i][j], left+right+gain);
             }
         }
     }
     printf("%lld\n", dp[1][n]);

}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     t=1;
     //scanf("%d",&t);
     while(t--){
         solve();
     }
}