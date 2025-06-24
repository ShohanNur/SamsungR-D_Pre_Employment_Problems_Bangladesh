#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>

int manhattan(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int n, pii src, pii dest, vector<tuple<pii, pii, int>>& wormholes) {
    vector<pii> nodes;
    nodes.push_back(src);
    nodes.push_back(dest);

    for (auto& wh : wormholes) {
        nodes.push_back(get<0>(wh));
        nodes.push_back(get<1>(wh));
    }

    int sz = nodes.size();
    vector<vector<pair<int, int>>> adj(sz);

    // Add direct travel edges
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (i != j) {
                int d = manhattan(nodes[i], nodes[j]);
                adj[i].push_back({j, d});
            }
        }
    }

    // Add wormhole edges (bi-directional)
    for (int i = 0; i < wormholes.size(); i++) {
        pii a = get<0>(wormholes[i]);
        pii b = get<1>(wormholes[i]);
        int cost = get<2>(wormholes[i]);

        int ai = find(nodes.begin(), nodes.end(), a) - nodes.begin();
        int bi = find(nodes.begin(), nodes.end(), b) - nodes.begin();

        adj[ai].push_back({bi, cost});
        adj[bi].push_back({ai, cost});
    }

    // Dijkstra from src (index 0) to dest (index 1)
    vector<int> dist(sz, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        pii src = {x1, y1};
        pii dest = {x2, y2};

        vector<tuple<pii, pii, int>> wormholes;

        for (int i = 0; i < n; i++) {
            int a, b, c, d, cost;
            cin >> a >> b >> c >> d >> cost;
            wormholes.push_back({{a, b}, {c, d}, cost});
        }

        cout << solve(n, src, dest, wormholes) << endl;
    }
    return 0;
}
