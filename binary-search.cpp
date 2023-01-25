#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

// binary search of sqrt(n) in O(logN)
// more accurate than sqrt() for large numbers (>10^10)
ll sqrtBS(ll x) { 
	ll l = 1, r = 2e11;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (mid * mid > x) r = mid;
		else l = mid + 1;
	}
	return l - 1;
}

int main() {
	int n = 5;
	int arr[n];
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int tar = 15;
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (array[mid] >= tar) { // bisect left (minimal/earliest idx)
			ans = mid; 
			r = mid - 1;
		}
		else l = mid + 1;
	}

	while (l <= r) {
		int mid = (l + r) / 2;
		if (array[mid] <= tar) { // bisect right (maximal/latest idx)
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	while (l <= r) { // smallest element greater than target
		int mid = (l + r) / 2;
		if (array[mid] <= tar)l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}

	while (l <= r) { // biggest element smaller than target
		int mid = (l + r) / 2;
		if (array[mid] >= tar) r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
}