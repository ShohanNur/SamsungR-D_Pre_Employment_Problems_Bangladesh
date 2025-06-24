#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      500001
#define endl     "\n"
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define eps      1e-6
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;


class Node
{
public:
   int val;
   Node *left;
   Node *right;

   Node(int v) {
      val = v;
      left = NULL;
      right = NULL;
   }
};

void build(string &s, Node *&root) {

   // remove first and last ()
   s.erase(s.begin());
   s.pop_back();

   if (s.size() == 0) {
      return;
   }

   int ans = 0;
   int i;

   for (i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
         break;
      }
      ans = ans * 10 + (s[i] - '0');
   }

   root = new Node(ans);

   int cnt1 = 0;
   int j;
   string leftSide = "", rightSide = "";
   for (j = i; j < s.size(); j++) {
      leftSide += s[j];
      if (s[j] == '(') {
         cnt1++;
      }
      if (s[j] == ')') {
         cnt1--;
      }
      if (cnt1 == 0) {
         break;
      }
   }
   cnt1 = 0;
   for (int k = j + 1; k < s.size(); k++) {
      rightSide += s[k];
      if (s[k] == '(') {
         cnt1++;
      }
      if (s[k] == ')') {
         cnt1--;
      }
      if (cnt1 == 0) {
         break;
      }
   }

   build(leftSide, root->left);
   build(rightSide, root->right);
}

int evaluate(Node *root, int k) {

   int sum = 0;

   queue<pair<Node * , int>> q;

   q.push({root, 0});

   while (!q.empty()) {

      auto it = q.front();
      q.pop();

      if (it.second == k) {
         sum += it.first->val;
      }
      if (it.first->left) {
         q.push({it.first->left, it.second + 1});
      }
      if (it.first->right) {
         q.push({it.first->right, it.second + 1});
      }
   }
   return sum;
}

void solve()
{
   int k;
   cin >> k;
   string s;
   cin >> s;
   Node *root;
   build(s, root);

   cout << evaluate(root, k) << endl;

}
int32_t main()
{
   fastio
   int t = 1;


   //cin>>t;
   while (t--) {
      solve();
   }
}
