#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_width(vector<int> &arr)
{
	int n = arr.size();	// array size
	// current and maximum widths
	int curr_wid = 0, max_wid = INT_MIN;
	// traversing array
	for(int i=1; i<n-1;) {
		// if arr[i] is a peak
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
			int j = i;	// index for back traversal
			// x -> width on left
			// y -> width on right
			int x = 0, y = 0;
			// back traversal
			while(j>=0 && arr[j]>arr[j-1]) {
				x++;	// left_width++
				j--;	// keep going back
			}
			// forward traversal
			while(i<n-1 && arr[i]>arr[i+1]) {
				y++;	// right_width++
				i++;	// keep going forward
			}
			// current_width = left_width + right_width
			curr_wid = x + y;
			// check for maximum
			max_wid = max(max_wid, curr_wid);
		} else i++;	// else just keep moving in array
	}
	// return maximum width
	return max_wid;
}

int main()
{
	vector<int> arr = {1, 2, 5, 6, 3, 2, 4, 2, 3};
	cout << max_width(arr) << endl;

	return 0;
}