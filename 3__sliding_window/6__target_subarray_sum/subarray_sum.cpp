#include <bits/stdc++.h>
using namespace std;

int subarray_sumk(vector<int> arr, int k)
{
	int cnt = 0;

	unordered_map<int, int> mp;
	int sum = 0;
	for(int i=0; i<arr.size(); i++) {
		// add current element to sum
		sum += arr[i];

		// if sum is equal to target sum
		if(sum == k)
			cnt++;	// increase the count

		// sum exceeds the given target by (sum-k).
		// we find all the subarrays with that add up to (sum-k)
		// from the map and add that number to the count
		if(mp.find(sum - k) != mp.end())
			cnt += mp[sum - k];

		mp[sum]++;	// add the current sum to the map
	}

	return cnt;
}

int main()
{
	int k = -10;
	vector<int> arr = {10, 2, -2, -20, 10};

	cout << subarray_sumk(arr, k) << endl;

	return 0;
}