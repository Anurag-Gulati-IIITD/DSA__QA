#include <bits/stdc++.h>
using namespace std;

// partition is the same as in quick sort
int partition(vector<int> &arr, int st, int en)
{
	int i=st-1, j=st;
	int piv=arr[en];

	int temp;
	while(j<en) {
		if(arr[j] < piv) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		} j++;
	}

	temp = arr[i+1];
	arr[i+1] = arr[en];
	arr[en] = temp;

	return i+1;
}

// small changes in quick selects.
// the idea is that if the pivot > k, then we only have to
// sort the left side of pivot. else, if pivot < k, we only have to
// sort the right side of the pivot. else, if pivot == k, then we 
// have reached the desired result, and we can return it.
int quick_select(vector<int> &arr, int st, int en, int k)
{
	if(st == en && st == k)
		return arr[st];
	if(st > en || (st == en && st != k))
		return INT_MIN;
	int pivot = partition(arr, st, en);
	if(pivot == k)
		return arr[pivot];
	if(pivot > k)
		return quick_select(arr, st, pivot-1, k);
	return quick_select(arr, pivot+1, en, k);
}

int main()
{
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int k = 7;
	cout << quick_select(arr, 0, arr.size()-1, k-1) << endl;	

	return 0;
}