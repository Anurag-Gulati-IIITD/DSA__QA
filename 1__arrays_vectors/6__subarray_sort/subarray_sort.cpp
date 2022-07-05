#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// function to check if an element is out of sorted order
bool out_of_order(vector<int> arr, int i)
{
	if(i == 0)
		return arr[i] > arr[i+1];
	if(i == arr.size()-1)
		return arr[i] < arr[i-1];

	return arr[i]>arr[i+1] || arr[i]<arr[i-1];
}

pair<int, int> subarray_sort(vector<int> &arr)
{
	int n = arr.size();

	int smallest = INT_MAX;	// smallest element out of order
	int largest = INT_MIN;	// largest element out of order

	for(int i=0; i<n; i++) {
		if(out_of_order(arr, i)) {	// if i-th element is out of order
			// check if it is smallest or largest element
			// that is out of order
			smallest = min(smallest, arr[i]);	
			largest = max(largest, arr[i]);
		}
	}

	if(smallest==INT_MIN)	// indicates if the array is already sorted
		return make_pair(-1, -1);	// return <-1, -1>

	int st = 0, en = n-1;	// start and end of unsorted subarray
	// finding the correct positions of the smallest
	// and the largest elements that are out of order
	while(arr[st] <= smallest)
		st++;
	while(arr[en] >= largest)
		en--;

	return make_pair(st, en);	// return <st, en>

}

int main()
{
	vector<int> arr = {1, 3, 4, 2, 3, 5};
	
	auto p = subarray_sort(arr);
	cout << '[' << p.first << ' ' << p.second << ']' << endl;

	return 0;
}