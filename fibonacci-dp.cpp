#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

ll ans = 0;

// STATE = f(n) (what you initially know)
// TRANSITIONS = f(n) = f(n-1) + f(n-2) (using only previous values)
// BASE CASES = f(0) = 0, f(1) = 1

ll cache[10000]; // memoization 
ll f(ll n){
	if (n < 2) return n;
	if (cache[n] > 0) {
		return cache[n];
	}
	cache[n] = f(n - 1) + f(n - 2);
	return cache[n];
}

// pull iterative dp <---
ll fib[10000]
ll pullDP(ll n) {
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= n; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	return f[n - 1];
}

// push iterative dp --->
ll fib[10000]
ll pushDP(ll n) {
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 0; i <= n-1; ++i) {
		fib[i + 1] += fib[i];
		fib[i + 2] += fib[i];
	}
	
	return f[n - 1];
}

int main(){
	ll n;
	cin >> n;

	ans = dp(n);
	cout << ans << endl;
}