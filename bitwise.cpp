#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() {
	int k = 3;

	1LL << n; // computes 2^n
	k & (1LL << k); // returns value of k-th bit
	k | (1LL << k); // alters k-th bit to 1
	__builtin_popcount(k); // returns number of '1' bits in k
	__builtin_popcountll(k); // for long longs

	__builtin_clz(k); // counts leading zeros
	// __builtin_clz(0) = 32, __builtin_clzll(0) = 64
	__builtin_ctz(k); // counts trailing zeros

	bitset<300> b("10101010"); // binary number with 300 avaliable bits
	b.count(); // same as popcount
	b.flip() // flip all bits or flip a bit at specific position (from right)
	cout << b[i] << "\n"; // returns i-th bit
}