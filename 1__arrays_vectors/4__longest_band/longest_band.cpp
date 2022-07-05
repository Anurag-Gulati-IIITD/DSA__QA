#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longest_band(vector<int> &arr)
{
	// set containing all array elements
	// for look-up
	unordered_set<int> set;

	// array size
	int n = arr.size();
	// maximum band length
	int max_band = INT_MIN;

	// adding array elements to the set
	for(int i=0; i<n; i++)
		set.insert(arr[i]);

	// traversing the array
	for(int i=0; i<n; i++) {
		// if the number next to arr[i]
		// exists in the array, continue
		if(set.find(arr[i]+1) != set.end())
			continue;
		// if the next number does not exist,
		// we need to perform back traversal
		int count = 0;
		int curr_ele = arr[i];	// current element
		// while the reverse trail exists in the array,
		// we keep increasing the count
		while(set.find(curr_ele) != set.end()) {
			curr_ele--;
			count++;
		}
		// finding maximum band length
		max_band = max(max_band, count);
	}

	// returning maximum band length
	return max_band;
}

int main()
{
	vector<int> arr = {1, 9, 3, 0, -1, 5, 2, 4, 10, 7, 12, 6};
	cout << longest_band(arr) << endl;

	return 0;
}