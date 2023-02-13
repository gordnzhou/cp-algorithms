#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

vector<int> par, prio;

void make_set(int v) {
    par[v] = v;
    prio[v] = 0;
}

int find_set(int v) {
    if (v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;

    // higher prio dominates (x in this case)
    // prio = number of children
    if (prio[x] < prio[y]) swap(x, y);
    par[y] = x;
    if (prio[x] == prio[y]) prio[x]++;
}

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--; e.v--;
        edges.push_back(e);
    }

    int cost = 0;
    vector<Edge> res;
    par.resize(n); 
    prio.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }

    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) == find_set(e.v)) continue;
        cost += e.w;
        res.push_back(e);
        union_sets(e.u, e.v);
    }
    cout << cost << " ";
}