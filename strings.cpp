#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() {
	string s;
	int n;
	cin >> s >> n;
	int x1 = stoi(s); // number string -> same number as int
	s = to_string(3832);

	// make sure to type cast if not an explicit variable
	char c = (n + 'a'); // number [0, 25] -> char [a, z]
	int x = (int)(s[0] - 'a'); // char [a, z] -> number [0, 25]


	unordered_set<size_t> ust; // can keep hashes here
	hash<string> hasher; // hashers the type: string

	s = "uvnhrefgnhsdrfgoqomiowgheg"
	size_t hsh = hasher(s); // always returns size_t!
	ust.insert(hsh);
}