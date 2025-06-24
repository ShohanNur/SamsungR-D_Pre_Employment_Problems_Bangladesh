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

#define    pb    push_back
#define    endl  "\n"
#define    s     second
#define    f     first

using namespace std;
typedef long long ll;


void merge(vector<int>&a, int mid, int low, int high){

	  int l = low, r = mid+1; 
	  vector<int>temp; 

	  while(l <= mid and r <= high){
	  	   if(a[l] <= a[r]){
	  	   	   temp.pb(a[l]);
	  	   	   l++;
	  	   }
	  	   else if(a[r] <= a[l]){
	  	   	   temp.pb(a[r]);
	  	   	   r++;
	  	   }
	  }   

	  while(l <= mid){
	  	  temp.pb(a[l]);
	  	  l++;
	  }

	  while(r <= high){
	  	  temp.pb(a[r]);
	  	  r++;
	  }

	  for(int i=low ; i<=high ; i++){
	  	  a[i] = temp[i-low];
	  }
}

void mergesort(vector<int>&a, int low, int high){

	  if(low>=high){
	  	 return;
	  }

	  int mid = (low+high)/2;

	  mergesort(a,low,mid);
	  mergesort(a,mid+1,high);
	  merge(a,mid,low,high);
}

void solve(){
    int n,k; 
    cin>>n>>k;
    

    vector<int>a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    mergesort(a,0,n-1);
     
    ll ans=0;
    int left = n;
    for(int i=0;i<k;i++){
        int diff;
        if(i==0){
            diff = a[i];
        }
        else{
            diff = a[i]-a[i-1];
        }
        ans += 1LL * diff * left;
        left--;
    }
    cout<<ans<<endl;
}
 
int main(){
	  int t; 
	  cin>>t;

	  while(t--){
	  	  solve();
	  }
}