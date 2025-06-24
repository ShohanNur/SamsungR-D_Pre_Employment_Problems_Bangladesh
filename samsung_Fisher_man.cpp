#include <bits/stdc++.h>
using namespace std;

int n;
int gatePos[3], gateFisher[3];
vector<pair<int, int>> dist[3]; // (distance, spot_index)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 3; i++) cin >> gatePos[i];
    for (int i = 0; i < 3; i++) cin >> gateFisher[i];

    for (int g = 0; g < 3; g++) {
        dist[g].clear();
        for (int i = 0; i < n; i++) {
            int d = abs(gatePos[g] - 1 - i) + 1;
            dist[g].emplace_back(d, i);
        }
        sort(dist[g].begin(), dist[g].end());
    }

    vector<int> perm = {0, 1, 2};
    int answer = INT_MAX;

    do {
        // dp[mask][gate][count] = minimum cost so far
        // mask: bitmask of occupied spots
        // gate: current gate index in perm
        // count: fishermen assigned from current gate
        vector<vector<vector<int>>> dp(
            1 << n, vector<vector<int>>(4, vector<int>(16, INT_MAX)));

        dp[0][0][0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int g = 0; g < 3; g++) {
                for (int cnt = 0; cnt <= gateFisher[perm[g]]; cnt++) {
                    if (dp[mask][g][cnt] == INT_MAX) continue;
                    int cost = dp[mask][g][cnt];
                    // If all fishermen assigned for current gate
                    if (cnt == gateFisher[perm[g]]) {
                        // Move to next gate
                        if (g + 1 <= 3) {
                            dp[mask][g + 1][0] = min(dp[mask][g + 1][0], cost);
                        }
                        continue;
                    }
                    // Assign next fisherman to any free spot
                    for (auto &[distv, spot] : dist[perm[g]]) {
                        if ((mask & (1 << spot)) == 0) {
                            int new_mask = mask | (1 << spot);
                            dp[new_mask][g][cnt + 1] =
                                min(dp[new_mask][g][cnt + 1], cost + distv);
                        }
                    }
                }
            }
        }

        // After all gates are processed (g=3), find minimum cost
        for (int mask = 0; mask < (1 << n); mask++) {
            answer = min(answer, dp[mask][3][0]);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << answer << "\n";
    return 0;
}
