#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int lo, int hi)
{
	int i = lo;
	int mid = (lo+hi)/2;
	int j = mid+1;

	// temporary array to store sorted elements
	vector<int> temp;	

	// comparing elements of the two subarrays
	// and storing in temp as required
	while(i<=mid && j<=hi) {
		if(arr[i] < arr[j])
			temp.push_back(arr[i++]);
		else
			temp.push_back(arr[j++]);
	}

	// completing the insertion of the remaining elements
	while(i<=mid)
		temp.push_back(arr[i++]);
	while(j<=hi)
		temp.push_back(arr[j++]);

	// storing back in the original array
	int idx=0;
	for(int k=lo; k<=hi; k++)
		arr[k] = temp[idx++];

}

void mergesort(vector<int> &arr, int lo, int hi)
{
	if(lo >= hi)	// if only one or no element left
		return;	// return as it is

	int mid = (lo+hi)/2;	// partitioning index

	// recursive call on the two subarrays
	mergesort(arr, lo, mid);
	mergesort(arr, mid+1, hi);

	// merging the sorted subarrays
	return merge(arr, lo, hi);
}

// driver function to be called
void msort(vector<int> &arr)
{
	mergesort(arr, 0, arr.size()-1);
}

int main()
{
	vector<int> arr = {3, 2, 4, 1, 7, 8, 5};
	msort(arr);

	for(int ele : arr)
		cout << ele << " ";
	cout << endl;

	return 0;
}