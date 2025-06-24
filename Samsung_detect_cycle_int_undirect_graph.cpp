#include<bits/stdc++.h>
#define pb       push_back
#define endl     "\n"
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
using namespace std;

vector<int> graph[1001];
vector<int> best;
int mn = INT_MAX;
int vis[1001];

void dfs(int u, int from, vector<int>& path) {
    vis[u] = 1;
    path.pb(u);

    for (auto v : graph[u]) {
        if (!vis[v]) {
            dfs(v, u, path);
        } else if (v != from) {
            // cycle detected
            auto it = find(path.begin(), path.end(), v);
            if (it != path.end()) {
                vector<int> cycle(it, path.end());
                int sum = accumulate(cycle.begin(), cycle.end(), 0);
                if (sum < mn) {
                    mn = sum;
                    best = cycle;
                }
            }
        }
    }

    path.pop_back();
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        vis[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    best.clear();
    mn = INT_MAX;
    vector<int> path;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1, path);
        }
    }

    if (best.empty()) {
        cout << "No cycle found" << endl;
    } else {
        sort(best.begin(), best.end());
        for (auto node : best) cout << node << " ";
        cout << endl;
    }
}

int32_t main() {
    fastio
    int t = 1;
    while (t--) solve();
}


/*
using parent array 
#include<bits/stdc++.h>
#define pb       push_back
#define f        first
#define s        second
#define inf      1e9
#define endl     "\n"
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
using namespace std;

vector<int>graph[1001];
vector<int>best;
int mn = INT_MAX;
int vis[1001];
int parent[1001];

void dfs(int u, vector<int>&path) {
    vis[u] = 1;
    path.pb(u);

    for (auto v : graph[u]) {
        if (!vis[v]) {
            parent[v] = u;
            dfs(v, path);
        } else if (v != parent[u]) {
            vector<int>cycle;
            int cur = u;
            cycle.pb(v);
            while (cur != v) {
                cycle.pb(cur);
                cur = parent[cur];
            }
            cycle.pb(v);
            int sum = 0;
            for (auto node : cycle) sum += node;
            if (sum < mn) {
                mn = sum;
                best = cycle;
            }
        }
    }

    path.pop_back();
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        graph[i].clear();
        vis[i] = 0;
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    vector<int>path;
    best.clear();
    mn = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, path);
        }
    }

    if (best.size() == 0) {
        cout << "No cycle found" << endl;
    } else {
        sort(best.begin(), best.end());
        for (auto i : best) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    fastio
    int t = 1;
    while (t--) {
        solve();
    }
}
*/