#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m, x, y, z, s;
    cin >> n >> m;

    vector<bool> vis(n, 0);
    vector<int> dist(n, INF);
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        // edge between node 'x' and node 'y' with weight 'z'
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    cin >> s; // starting node s

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int tp = pq.top().second;
        pq.pop();
        if (vis[tp]) continue;
        vis[tp] = true;
        
        for (auto a : adj[tp]) {
            int v = a.first, w = a.second;
            if (dist[v] > dist[tp] + w) {
                dist[v] = dist[tp] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}