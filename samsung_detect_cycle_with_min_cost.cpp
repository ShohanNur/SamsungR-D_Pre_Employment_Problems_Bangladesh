#include <bits/stdc++.h>
using namespace std;

#define inf 1e18
typedef long long ll;

vector<vector<int>> graph;
vector<int> path, best;
vector<int> vis;
int mn = INT_MAX;

void dfs(int u) {
    vis[u] = 1;
    path.push_back(u);

    for (int v : graph[u]) {
        if (vis[v] == 0) {
            dfs(v);
        } 
        else {
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

    vis[u] = 0;
    path.pop_back();
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph.assign(n + 1, {});
    vis.assign(n + 1, 0);
    best.clear();
    path.clear();
    mn = INT_MAX;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
           if(!vis[i]){
              dfs(i);
           }
    }

    if (best.empty()) {
       cout<<-1<<endl;
    } else {
        sort(best.begin(),best.end());
        for (int x : best) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
