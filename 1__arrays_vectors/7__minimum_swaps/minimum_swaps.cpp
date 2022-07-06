#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_swaps(vector<int> &arr)
{
	int n = arr.size();	// array size
	vector<pair<int, int>> ap(n);	// new array of pairs

	// pair -> first : array element
	// pair -> second : original index of the element
	for(int i=0; i<n; i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	// sort the new array
	sort(ap.begin(), ap.end());

	// storing the answer 
	int ans = 0;
	// visited array to keep check while traversing
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++) {
		// if the element has been traversed, then move on
		if(visited[i]) {	
			continue;
		}
		// size of the swap cycle
		int cycle_size = 0;
		// while the element hasn't been visited
		while(!visited[i]) {
			visited[i] = true;	// mark as visited
			i = ap[i].second;	// move to ap[i].second
			cycle_size++;	// add 1 to cycle size
		}
		ans += cycle_size-1;	// no. of swaps = cycle size - 1
	}

	return ans;	// return answer
}

int main()
{
	vector<int> arr = {2, 4, 5, 1, 3};
	cout << min_swaps(arr) << endl;

	return 0;
}