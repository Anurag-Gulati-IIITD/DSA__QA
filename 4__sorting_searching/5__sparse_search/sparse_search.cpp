#include <bits/stdc++.h>
using namespace std;

// modified binary search
// worst: O(N)
// avg: theta(logN)
bool sparse_search(vector<string> arr, string key)
{
	int st=0, en=arr.size()-1;
	while(st <= en) {
		int mid=(st+en)/2;
		// this is the only modified block
		if(arr[mid] == "") {
			// IDEA: if the string at index mid is empty, we
			// don't know whether to move left or right. so,
			// we move in both directions to find the nearest 
			// non-empty string in the array, and set that
			// as the mid index string.
			int L=mid-1, R=mid+1;
			while(true) {
				if(L < st || R > en)
					return false;
				if(arr[L] != "") {
					mid=L;
					break;
				} if(arr[R] != "") {
					mid=R;
					break;
				} L--; R++;
			}
		}
		if(arr[mid] == key) {
			return true;
		} if(arr[mid] > key) {
			en = mid-1;
		} else {
			st = mid+1;
		}
	}

	return false;
}

int main()
{
	vector<string> arr = {"ai","","","bat","","","cat","cat","","","dog","e"};
	cout << sparse_search(arr, "bat") << endl;	

	return 0;
}