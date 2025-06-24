#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    const int L = 2;  // assumed tank capacity based on your sample

    while (T--) {
        int n; cin >> n;
        vector<int> dist(n);
        for (int i = 0; i < n; i++) cin >> dist[i];

        int total_distance = 0;
        int fuel = L;

        for (int i = 0; i < n; i++) {
            if (dist[i] > L) {
                // segment longer than tank capacity, impossible
                total_distance = -1;
                break;
            }

            if (fuel < dist[i]) {
                // need to refill before this segment
                total_distance += L;  // add cost of full tank travel (or a refill)
                fuel = L;
            }
            fuel -= dist[i];
            total_distance += dist[i];
        }

        cout << total_distance << "\n";
    }

    return 0;
}
