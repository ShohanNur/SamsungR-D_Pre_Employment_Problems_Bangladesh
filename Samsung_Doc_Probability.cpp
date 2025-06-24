#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, T;
        cin >> n >> m >> T;

        vector<int> adj[n + 1];
        vector<double> weight[n + 1];

        for (int i = 0; i < m; i++) {
            int u, v;
            double p;
            cin >> u >> v >> p;
            adj[u].push_back(v);
            weight[u].push_back(p);
        }

        double prob[n + 1] = {0};

        queue< pair<int, pair<double, int>> > q;
        q.push({1, {1.0, 0}}); // {node, {probability, current_time}}

        while (!q.empty()) {
            int u = q.front().first;
            double p = q.front().second.first;
            int time = q.front().second.second;
            q.pop();
            prob[u] += p;

            if (time == T) {
                continue;
            }

            if (adj[u].empty()) {
                if (time + 10 == T) {
                    prob[u] += p;
                }
                continue;
            }

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                double w = weight[u][i];
                q.push({v, {p * w, time + 10}});
            }
        }

        int res_node = 1;
        double max_prob = prob[1];
        for (int i = 2; i <= n; i++) {
            if (prob[i] > max_prob) {
                max_prob = prob[i];
                res_node = i;
            }
        }

        cout << res_node << " ";
        printf("%.6f\n", max_prob);
    }
    return 0;
}
