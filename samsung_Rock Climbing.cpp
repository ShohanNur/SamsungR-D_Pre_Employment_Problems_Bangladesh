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

int a[15][15];
bool vis[15][15];
int n, m;
bool ok;

void dfs(int x, int y, int l) {


   vis[x][y] = 1;

   if (a[x][y] == 3) {
      ok = 1;
      return;
   }

   if (x >= 0 and x<n and y + 1 >= 0 and y + 1 < m and vis[x][y + 1] == 0 and a[x][y + 1] != 0) {
      dfs(x, y + 1, l);
   }
   if (x >= 0 and x < n and y - 1 >= 0 and y - 1 < m and vis[x][y - 1] == 0 and a[x][y - 1] != 0) {
      dfs(x, y - 1, l);
   }

   for (int i = 1; i <= l; i++) {
      if (x - i >= 0 and x - i < n and y >= 0 and y < m and vis[x - i][y] == 0 and a[x - i][y] != 0) {
         dfs(x - i, y, l);
      }
      if (x + i >= 0 and x + i < n and y >= 0 and y < m and vis[x + i][y] == 0 and a[x + i][y] != 0) {
         dfs(x + i, y, l);
      }
   }
}

void solve()
{

   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> a[i][j];
      }
   }

   for (int i = 0; i <= n; i++) {
      ok = 0;
      memset(vis, 0, sizeof vis);
      dfs(n - 1, 0, i);

      if (ok) {
         cout << i << endl;
         break;
      }
   }
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
