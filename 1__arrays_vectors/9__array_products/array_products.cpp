#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> array_product(vector<int> &arr)
{
	int n = arr.size();
	// prefix, suffix and result arrays
	vector<int> prefix(n), suffix(n);
	vector<int> res(n);

	// pre-setting prefix and suffix
	prefix[0] = 1; suffix[n-1] = 1;

	int cur_prod = 1;	// current product
	// filling prefix product arrays
	for(int i=1; i<n; i++) {
		cur_prod *= arr[i-1];
		prefix[i] = cur_prod;
	}

	cur_prod = 1;
	// filling suffix product arrays
	for(int j=n-2; j>=0; j--) {
		cur_prod *= arr[j+1];
		suffix[j] = cur_prod;
	}

	// filling result array
	for(int i=0; i<n; i++)
		res[i] = prefix[i] * suffix[i];

	return res;	// return result
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	auto res = array_product(arr);

	for(int ele:res)
		cout << ele << " ";
	cout << endl;

	return 0;
}