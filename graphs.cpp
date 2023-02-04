#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const int N = 1e5;

vector<vector<int>> adj(N);
vector<bool> vis(N, 0);

void dfs(int v) {
    vis[v] = true;
    //process node here
    for (auto a : adj[v]) {
        if (vis[a]) continue;
        dfs(a);
    }
}

int main() {
	
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int start = 0;

    // BFS
    queue<int> q;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto a : adj[f]) {
            if (vis[a]) continue;
            vis[a] = true;
            // process node here
            q.push(a);
        }
    }

    // DFS
    dfs(start);
}