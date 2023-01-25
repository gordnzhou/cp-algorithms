#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const int N = 1e5;

int st[4 * N]; 
// children nodes of i are at indexes 2*i and 2*i+1 
// can be used for range min, lcm, sum, etc.. (you just have to change the __gcd()!) 
// in O(log[n]) time!

void build(int *a, int idx, int l, int r) {
    if (l > r) return;
    if (l == r) {
        st[idx] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(a, 2 * idx, l, m);
    build(a, 2 * idx + 1, m + 1, r);
    st[idx] = st[2 * idx] + st[2 * idx + 1]; 
}

int query(int idx, int l, int r, int ql, int qr) {
    // case 1: query range is completely outside our range
    if (ql > r || l > qr) 
        return 0;

    // case 2: query range completely covers our range
    if (l >= ql && r <= qr) 
        return st[idx];

    // case 3: query range partially covers our range
    int m = (l + r) / 2;
    int lans = query(2 * idx, l, m, ql, qr);
    int rans = query(2 * idx + 1, m + 1, r, ql, qr);
    return lans + rans;
}

// updates a singular leaf node in ST
void pointUpdate(int idx, int l, int r, int tar, int val) {
    if (l == r) {
        // dependent on type of update 
        st[idx] += val;
        return;
    } 

    int m = (l + r) / 2;
    if (tar <= m)
        pointUpdate(2 * idx, l, m, tar, val);
    else
        pointUpdate(2 * idx + 1, m + 1, r, tar, val);
    
    // dependent on type of segment tree (min, gcd, sum?)
    st[idx] = st[2 * idx] + st[2 * idx + 1]; 
}

// can be slow! may requre lazy propagation for O(log[n]) run time
void rangeUpdate(int idx, int l, int r, int ql, int qr, int val) {
    // update range is complete outside our range
    if (l > qr || r < ql) return;
    if (l == r) {
        // dependent on type of update 
        st[idx] += val; 
        return;
    }

    int m = (l + r) / 2;
    rangeUpdate(2 * idx, l, m, ql, qr, val);
    rangeUpdate(2 * idx + 1, m + 1, r, ql, qr, val);

    // dependent on type of segment tree (min, gcd, sum?)
    st[idx] = st[2 * idx] + st[2 * idx + 1];
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int index = 1; // starting index

    build(a, index, 0, n - 1); 
    cout << query(index, 0, n - 1, 1, 3) << "\n"; 

    pointUpdate(index, 0, n - 1, 2, 10);
    cout << query(index, 0, n - 1, 1, 3) << "\n";

    rangeUpdate(index, 0, n - 1, 0, 2, 3);
    cout << query(index, 0, n - 1, 0, 4) << "\n";
}