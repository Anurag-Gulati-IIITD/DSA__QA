#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> housing(vector<int> areas, int target)
{
	// vector containing ranges
	vector<pair<int, int>> sol;

	// indexers
	int i=0, j=0, n=areas.size();
	int cur_sum = 0;

	// while the right pointer is in bounds
	while(j<n) {
		// add to current sum and move j ahead
		cur_sum += areas[j++];

		// while the sum is greater than target
		while(i<j && cur_sum > target)
			cur_sum -= areas[i++];	// subtract the elements

		// if target reached, make a pair
		if (cur_sum == target) {
			sol.push_back(make_pair(i, j-1));
		}
	}

	return sol;
}

int main()
{
	vector<int> areas = {1,3,2,1,4,1,3,2,1,1,2};
	int target = 8;
	auto res = housing(areas, target);

	for(auto p : res)
		cout << p.first << " " << p.second << endl;

	return 0;
}