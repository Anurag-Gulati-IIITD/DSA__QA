#include <bits/stdc++.h>
using namespace std;

// partition algorithm
int partition(vector<int> &arr, int st, int en)
{	
	// set the last element as pivot
	int pivot = arr[en];
	int i = st-1;	// i as start-1

	int temp;	// swapping variable
	// iterate j till before the pivot element
	for(int j=st; j<en; j++) {
		// if the current element is less than pivot
		if(arr[j] < pivot) {	
			i++;	// move i ahead
			// SWAP 
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// SWAP pivot element to its correct position,
	// that is, between the two subarrays
	temp = arr[i+1];
	arr[i+1] = arr[en];
	arr[en] = temp;

	// return new position of pivot, i.e. i+1
	return i+1;
}

void quicksort(vector<int> &arr, int st, int en)
{
	if(st >= en)	// base case
		return;

	// partition by pivot
	int pivot = partition(arr, st, en);
	// quick sort on left partition
	quicksort(arr, st, pivot-1);
	// quick sort on right partition
	quicksort(arr, pivot+1, en);
}

int main()
{	
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int n = arr.size();
	quicksort(arr, 0, n-1);

	for(int ele : arr)
		cout << ele << " ";
	cout << endl;

	return 0;
}