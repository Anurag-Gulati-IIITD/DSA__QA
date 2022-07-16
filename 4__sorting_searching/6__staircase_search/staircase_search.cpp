#include <bits/stdc++.h>
using namespace std;

pair<int, int> staircase_search(vector<vector<int>> mat, int key)
{
	int m=mat.size(), n=mat[0].size();
	int i=m-1, j=0;

	while(i>=0 && j<n) {
		if(mat[i][j] == key)
			return make_pair(i, j);
		if(mat[i][j] > key)
			i--;
		else
			j++;
	}

	return make_pair(-1, -1);
}

int main()
{
	vector<vector<int>> mat = {
		{1, 4, 9},
		{2, 5, 10},
		{6, 7, 11}
	};
	int key = 12;
	auto res = staircase_search(mat, key);
	cout<<res.first<<" "<<res.second<<endl;

	return 0;
}