#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>

#define    pb    push_back
#define    endl  "\n"
#define    f     first
#define    s     second
#define    inf   1e18
#define    mod   1000000007
#define    ll    long long

using namespace std;


void solve(){

	  int n; cin>>n;

	  vector<int>a(n+2);
       

	  for(int i=1;i<=n;i++){
	  	  cin>>a[i];
	  }
      a[0]=1;
      a[n+1]=1;

      int dp[20][20] = {};      
      for(int len=1;len<=n;len++){
      	   for(int i=1;i<=n-len+1;i++){
      	   	    int j = i+len-1;

      	   	    for(int k=i;k<=j;k++){
      	   	    	int left = dp[i][k-1];
      	   	    	int right = dp[k+1][j];
      	   	    	int gain = a[i-1] * a[k] * a[j+1];
      	   	    	dp[i][j] = max(dp[i][j] , left+right+gain);
      	   	    }
      	   }
      } 

      cout<<dp[1][n]<<endl;

}

int main(){
	 ios_base:: sync_with_stdio(false);
	 cin.tie(NULL);

	 int t;
	 t = 1; 
	 //cin>>t;
     while(t--){
     	 solve();
     }

}