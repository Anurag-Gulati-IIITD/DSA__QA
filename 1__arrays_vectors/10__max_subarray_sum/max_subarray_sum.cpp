#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &arr)
{
	// positive sum start and end indices
	int pos_sum_start = 0, pos_sum_end = 0;
	// current sum and maximum sum
	int cur_sum = 0, max_sum = INT_MIN;
	int n = arr.size();	// array size

	// while positive sum end index is within bounds
	while(pos_sum_end<n) {
		// current sum updated
		cur_sum += arr[pos_sum_end];

		// if sum becomes negative
		if(cur_sum<0) {
			// set current sum to 0
			cur_sum = 0;
			// increase positive sum start index
			pos_sum_start++;
		}
		// update maximum sum
		max_sum = max(max_sum, cur_sum);
		// increase positive sum end index
		pos_sum_end++;
	}

	// return maximum subarray sum
	return max_sum;
}

int main()
{
	vector<int> arr = {-1, 2, 3, 4, -2, 6, -8, 3};
	cout << max_subarray_sum(arr) << endl;

	return 0;
}