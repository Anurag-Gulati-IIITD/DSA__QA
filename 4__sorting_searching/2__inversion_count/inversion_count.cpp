#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int lo, int hi)
{
	int i = lo;
	int mid = (lo+hi)/2;
	int j = mid+1;

	int cnt = 0;

	// temporary array to store sorted elements
	vector<int> temp;	

	// comparing elements of the two subarrays
	// and storing in temp as required
	while(i<=mid && j<=hi) {
		if(arr[i] < arr[j])
			temp.push_back(arr[i++]);
		else {
			temp.push_back(arr[j++]);
			cnt += mid-i+1;
		}
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

	return cnt;

}

int mergesort(vector<int> &arr, int lo, int hi)
{
	if(lo >= hi)	// if only one or no element left
		return 0;	// return as it is

	int mid = (lo+hi)/2;	// partitioning index

	// recursive call on the two subarrays
	int left_cnt = mergesort(arr, lo, mid);
	int rt_cnt = mergesort(arr, mid+1, hi);
	int merge_cnt = merge(arr, lo, hi);

	// merging the sorted subarrays
	return left_cnt + rt_cnt + merge_cnt;
}

// driver function to be called
int inversion_count(vector<int> &arr)
{
	return mergesort(arr, 0, arr.size()-1);
}

int main()
{
	vector<int> arr = {0, 5, 2, 3, 1};
	cout << inversion_count(arr) << endl;	

	return 0;
}