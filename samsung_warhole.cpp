#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<climits>

#define  ll     long long
#define  endl   "\n"
#define  pb     push_back
#define  f      first
#define  s      second
#define  inf    1e18  
using namespace std;

map<pair<ll,ll>, vector<pair<pair<ll,ll>,ll>> > mp;
map<pair<ll,ll>, ll>vis;

ll dist(pair<ll,ll>&a , pair<ll,ll>&b){
     return abs(a.f-b.f) + abs(a.s-b.s);
}
void solve(){
      
      int n;
      cin>>n;
      int s1,s2,d1,d2;
      cin>>s1>>s2>>d1>>d2;
      vector<pair<ll,ll>>nodes; 
      pair<ll,ll>src = {s1,s2};
      pair<ll,ll>des = {d1,d2};
      nodes.pb(src);
      nodes.pb(des);
    
    
      for(int i=0;i<n;i++){
            int a,b,c,d,cost;
            cin>>a>>b>>c>>d>>cost;
            pair<ll,ll>ind = {a,b};
            pair<ll,ll>outd = {c,d};
            mp[ind].pb({outd,cost});
            mp[outd].pb({ind,cost});
            nodes.pb(ind);
            nodes.pb(outd);
      }
      map<pair<ll,ll>, ll>dis; 
      for(auto i:nodes){
          dis[i] = INT_MAX;
      }    
      
     priority_queue< pair<ll,pair<ll,ll>> , vector<pair<ll,pair<ll,ll>>> , greater<pair<ll,pair<ll,ll>>>> pq;
      
      pq.push({0,src});
      dis[src] = 0; 
    
      while(!pq.empty()){
           auto it = pq.top();
           pq.pop();
           pair<ll,ll> cur = it.s;
           int d = it.f;
           
           for(auto i:nodes){
                 ll d = dist(i,cur);
                 if(dis[cur]+d < dis[i]){
                      dis[i] = dis[cur] + d;
                      pq.push({dis[i],i});
                 }
           }
          
           for(auto i:mp[cur]){
                 pair<ll,ll> temp = i.f;
                 ll cost = i.s;
               
                 if(dis[cur] + cost < dis[temp]){
                      dis[temp] = dis[cur] + cost;
                      pq.push({dis[temp],temp}); 
                 }
           }
           
      }
     cout<<dis[des]<<endl;
      
}
int main() {
    
    int t;
    cin>>t;
    while(t--){
         solve();
    }
    return 0;
}
