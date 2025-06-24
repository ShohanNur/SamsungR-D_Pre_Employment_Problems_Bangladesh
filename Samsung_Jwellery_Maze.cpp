#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define f first
#define s second

int n;
int mx = 0;
vector<pair<int, int>> best;

void dfs(int x, int y, int point, vector<pair<int, int>>& path, vector<vector<int>>& v, vector<vector<int>>& vis) {
    if (x == n - 1 && y == n - 1) {
        if (point > mx) {
            mx = point;
            best = path;
        }
        return;
    }

    vis[x][y] = 1;
    path.push_back({x, y});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && v[nx][ny] != 1) {
            int extra = (v[nx][ny] == 2) ? 1 : 0;
            dfs(nx, ny, point + extra, path, v, vis);
        }
    }

    vis[x][y] = 0;
    path.pop_back();
}

void solve() {
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    mx = 0;
    best.clear();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<pair<int, int>> path;

    int start_jewel = (v[0][0] == 2) ? 1 : 0;
    dfs(0, 0, start_jewel, path, v, vis);

    for (auto& p : best) v[p.f][p.s] = 3;
    v[n - 1][n - 1] = 3;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    cout << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
