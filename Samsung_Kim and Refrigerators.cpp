#include <bits/stdc++.h>
#define pb push_back
#define inf 1e18
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
using namespace std;

typedef long long ll;

ll n;
vector<pair<ll,ll>> nodes;
pair<ll,ll> home, office;
ll dp[1<<16][16];

ll dist(pair<ll,ll> a, pair<ll,ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int tc) {
    cin >> n;
    ll sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    office = {sx, sy};
    home = {dx, dy};

    nodes.clear();
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        nodes.pb({x, y});
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = inf;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = dist(office, nodes[i]);
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int new_mask = mask | (1 << v);
                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist(nodes[u], nodes[v]));
            }
        }
    }

    ll ans = inf;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + dist(nodes[i], home));
    }

    cout << "# " << tc << " " << ans << endl;
}

int32_t main() {
    fastio;
    for (int t = 1; t <= 10; t++) {
        solve(t);
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18

ll n;
vector<pair<ll, ll>> nodes;
pair<ll, ll> home, office;
ll dp[1 << 16][16];

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll recur(int mask, int last) {
    if (mask == (1 << n) - 1) {
        return dist(nodes[last], home);
    }

    if (dp[mask][last] != -1) return dp[mask][last];

    ll ans = inf;

    for (int next = 0; next < n; next++) {
        if (!(mask & (1 << next))) {
            ll cost = dist(nodes[last], nodes[next]) + recur(mask | (1 << next), next);
            ans = min(ans, cost);
        }
    }

    return dp[mask][last] = ans;
}

void solve(int tc) {
    cin >> n;
    ll sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    office = {sx, sy};
    home = {dx, dy};

    nodes.clear();
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        nodes.push_back({x, y});
    }

    memset(dp, -1, sizeof(dp));

    ll ans = inf;
    for (int i = 0; i < n; i++) {
        ll cost = dist(office, nodes[i]) + recur(1 << i, i);
        ans = min(ans, cost);
    }

    cout << "# " << tc << " " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int t = 1; t <= 10; t++) {
        solve(t);
    }
}

*/