/*
PROBLEM STATEMENT: (IMPORTANT PROBLEM)
Given a binary array, find the maximum number of zeros in an array 
with one flip of a subarray allowed. A flip operation switches all 0s to 1s and 1s to 0s.
*/

#include <bits/stdc++.h>
using namespace std;

int max_zeros(vector<int> bin)
{
	// consider all 0s as -1 and all 1s as 1 and find the
	// maximum subarray sum in the bin array
	int pos_sum_start = 0, pos_sum_end = 0;
	int cur_sum = 0, max_sum = INT_MIN;
	while(pos_sum_end < bin.size()) {
		// the only modification is the way of taking sum
		if(bin[pos_sum_end] == 1)
			cur_sum += 1;
		else
			cur_sum += -1;

		if(cur_sum < 0) {
			cur_sum = 0;
			pos_sum_start++;
		}
		max_sum = max(max_sum, cur_sum);
		pos_sum_end++;
	}

	for(int i=0; i<bin.size(); i++) {
		if(bin[i]==0)
			max_sum++;
	}

	return max_sum;
}

int main()
{
	vector<int> bin = {0, 0, 0, 1, 0, 1};
	// cout << max_zeros(bin) << endl;

	string s = to_string(10);
	string sub = s.substr(1, 1);
	cout << sub << endl;

	return 0;
}