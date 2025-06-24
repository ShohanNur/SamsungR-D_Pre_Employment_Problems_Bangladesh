// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     string s="";
//     for(int i=0; i<n; i++){
//         s+="_";
//     }
    
//     priority_queue<pair<int, int>> pq;
//     pq.push({n,0});
//     for( int i=0; i<n; i++){
//         pair<int, int> front= pq.top();
//         pq.pop();
//         int indx= (front.first-1)/2+ front.second;
//         s[indx]= 'X';
//         cout<<s<<endl;
//         pq.push({indx- front.second, front.second});
//         pq.push({front.first/2, indx+1});
//     }
//     return 0;
    
// }
#include<iostream>
#include<vector>
using namespace std;

int main(){

      int n; 
      cin>>n;

      vector<char>v(n,'_'); 

      for(int i=0;i<n;i++){

            int mx = 0;
            int start = -1;
            int pos = -1;

            for(int j=0;j<n;){
                 if(v[j]=='_'){
                     int k = j;

                     while(k<n and v[k] =='_'){
                        k++;
                     }
                     int len = k - j;
                     if(len> mx){
                        mx = len;
                        start = j;
                     }
                     j = k;
                 }
                 else{
                     j++;
                 }
            }
            pos = start + (mx - 1)/2;
            v[pos] = 'X';

            for(auto ii:v){
                 cout<<ii<<" ";
            }
            cout<<endl;
      }
}