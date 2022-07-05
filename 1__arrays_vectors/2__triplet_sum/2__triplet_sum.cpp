#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> triplet_sum(vector<int> &arr, int target) 
{
	// sort the input array
	sort(arr.begin(), arr.end());

	int n = arr.size();	// array size
	// for every element in the array
	for(int k=0; k<n; k++) {
		int i = 0, j = n-1;	// two pointers i & j
		// O(logn) approach to find the elements
		// other than arr[k] in the triplet
		while(i < j) {	
			
			// avoiding repitition of elements
			if(i==k) i++;
			if(j==k) j--;
			if(i==j) break;

			// if triplet found, return it as vector
			if(arr[k]+arr[i]+arr[j] == target) {
				vector<int> res = {arr[i], arr[k], arr[j]};
				return res;
			} 
			// if sum > target, reduce j by 1
			else if(arr[k]+arr[i]+arr[j] > target) j--;
			else i++;	// else increase i by 1

		}
	}

	// in case triplet not found, return this vector
	vector<int> res_nf = {INT_MIN, INT_MIN, INT_MIN};
	return res_nf;
}

int main()
{
	vector<int> arr = {-1, 5, 2, 0, 8, 10, 4, -3, -1, 0, 3};
    int target = 14;

    auto vec = triplet_sum(arr, target);
    
    cout << vec[0] << " " << vec[1] << " " << vec[2] << '\n';
    cout << endl;

	return 0;
}