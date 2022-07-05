#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rainwater(vector<int> &arr)
{
	int amt = 0;	// amount of rainwater

	// arrays containing maximum height block
	// from left side and right side respectively
	vector<int> left_max, right_max;
	int n = arr.size();	// array size

	// filling the left_max array with maximum
	// elements from the left size
	int curr_left_max = INT_MIN;
	for(int i=0; i<n; i++) {
		curr_left_max = max(arr[i], curr_left_max);
		left_max.push_back(curr_left_max);
	}

	// filling the right_max array with maximum
	// elements from the right size
	int curr_right_max = INT_MIN;
	for(int i=n-1; i>=0; i--) {
		curr_right_max = max(arr[i], curr_right_max);
		right_max.push_back(curr_right_max);
	}

	// reverse the right_max array since it has
	// been filled in the reverse order than what is required
	reverse(right_max.begin(), right_max.end());

	// calculating the amount of rainwater trapped by
	// adding up the amount trapped in different slots
	for(int i=0; i<n; i++)
		amt += min(left_max[i], right_max[i]) - arr[i];

	// returning the amount of rainwater trapped 
	return amt;
}

int main()
{
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << rainwater(arr) << endl;

	return 0;
}