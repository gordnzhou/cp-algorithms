#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main() {
	// STL VECTORS
	sort(a.begin(), a.end(), greater<>()); // sort by descending
	sort(a.rbegin(), a.rend()); // also works

	// sorts while maintaining relative order of equal elements
	stable_sort(a.begin(), a.end())
	reverse(a.begin(), a.end()); // reversing an array
	swap(a[0], a[1]); 
	a.reserve(x) // specify a min size for vector
	a.pop_back() // removes last element

	// middle argument will become first element 
	// takes O(n) time
	rotate(a.begin(), a.begin() + 1, a.end());


	// STL MAP
	mp.count("hello"); // checks if map 'mp' has key 'hello'
	mp.insert({"key", "element"}); // for maps, and multisets
	mp.clear();
	mp.erase(1) // erases key: 1 from mp, reducing size by 1

	// returns iterator ponting to element with key = x (or to mp.end() if not found)
	mp.find(x)

	// STL SET
	set<int> s;
	s.insert(x); // inserts value
	s.erase(x); // deletes by value
	cout << *(s.begin()) << "\n"; // get first (least) element in s

	// returns pointer to smallest element EQUAL OR GREATER than x
	s.lower_bound(x); // works for maps and sets
	lower_bound(v.begin(), v.end(), x); // for vector
	
	// returns smallest element STRICTLY GREATER than x
	s.upper_bound(x);


	int arr[N][N]; // 2d array example of memset
	memset(arr, 0, N*N*sizeof(int));

	// TO ADD: QUEUES, STACKS, PRIORITY QUEUES

	//range-based for loop + auto keyword
	for (auto a : arr) {
		cout << a << " ";
	} 
	cout << "\n";
}