#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

vector<int> primes;

// finds all primes in range [2, n] in O(n log[log(n)]) time
void sieve(int n) {
    vector<bool> prime(n + 1, 1);

    for (int p = 2; p * p <= n; p++) {
        if (!prime[p]) continue;
        for (int i = p * p; i <= n; i += p) {
            prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++) {
        if (prime[p]) primes.emplace_back(p);
    }
}

int main() {
    int n;
    cin >> n;
	sieve(n);
	for (auto p : primes) {
		cout << p << " ";
	}
	cout << "\n";
}