#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() {
	// STRINGS
	string s;
	int n;
	cin >> s >> n;
	int x1 = stoi(s); // number string -> same number as int
	char c = ('a' + n - 1); // number 1-26 -> char
	int x = (s[0] - 'a' + 1); // char -> number 1-26

	// BITWISE
	int k = 3;
	1LL << n; // computes 2^n
	k & (1LL << k); // returns value of k-th bit
	k | (1LL << k); // alters k-th bit to 1

	s = "sdlkfjsdklfsdj";

	unordered_set<size_t> ust; // can keep hashes here

	hash<string> hasher; // hashers the type: string
	size_t hsh = hasher(s); // always returns size_t!
	ust.insert(hsh);
}