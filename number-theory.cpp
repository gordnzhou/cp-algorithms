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

//check if n is a perfect square in O(log n)
bool is_ps(ll n) {
    ll sr = sqrt(n);
    return sr * sr == n;
}

int main() {
    int n;
    cin >> n;
    
	sieve(n);
	for (auto p : primes) {
		cout << p << " ";
	}
	cout << "\n";

    // finds all divisors of n in O(sqrt(n))
    // works because a divisor of n cannot exist in the interval (sqrt(n), n)
    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        cout << i << " ";
    }

    // prime factorization of 'n'
    vector<int> pf;
    int x = n;
    for (int i = 2; i * i <= n; i++) {
        while (x % i == 0) {
            pf.push_back(i);
            x /= i;
        }
    }
    if (x > 1) pf.push_back(x);

    for (auto &f : pf) {
        cout << f << " ";
    }
    cout << "\n";
}