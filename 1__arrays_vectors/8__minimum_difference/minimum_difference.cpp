#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> min_diff(vector<int> &A, vector<int> &B)
{
	// sort the two arrays
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int i=0, j=0;	// indexing variables
	int m=A.size(), n=B.size();	// array sizes

	// resultant pair
	pair<int, int> res = make_pair(INT_MIN, INT_MIN);
	int cur_diff=0, min_diff=INT_MAX;
	// while neither array is exhausted
	while(i<m && j<n) {
		cur_diff = abs(A[i]-B[j]);	// current difference
		min_diff = min(cur_diff, min_diff);	// minimum difference

		// if current difference is minimum, make a pair
		if(min_diff==cur_diff)
			res = make_pair(A[i], B[j]);

		// increment the index of the array with smaller element
		if(A[i]<B[j]) i++;
		else j++;
	}

	// return result
	return res;
}

int main()
{
	vector<int> A = {23, 5, 10, 17, 30};
	vector<int> B = {26, 134, 135, 14, 19};

	auto res = min_diff(A, B);
	cout << res.first << " " << res.second << endl;

	return 0;
}