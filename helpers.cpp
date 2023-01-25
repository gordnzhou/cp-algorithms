#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() {
	// STRINGS
	string s;
	cin >> s;
	int n = s - '0' // number string -> same number as int
	(char)('a' + n - 1); // number 1-26 -> char
	(int)(s[i] - 'a' + 1) // char -> number 1-26

	// BITWISE
	1LL << n // computes 2^n
	k & (1LL << k) // returns value of k-th bit
	k | (1LL << k) // alters k-th bit to 1
}