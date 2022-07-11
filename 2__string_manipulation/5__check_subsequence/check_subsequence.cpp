#include <bits/stdc++.h>
using namespace std;

bool is_subseq(string str, string sub)
{
	// size mismatch condition
	if(str.size() < sub.size())
		return false;

	// i: indexer for str, j: indexer for sub
	int i = 0, j = 0;
	// string sizes
	int m = str.size(), n = sub.size();
	// length if str and sub matched
	int matched_length = 0;

	// while both i and j are in bounds
	while(i<m && j<n) {
		// if character matches
		if(str[i] == sub[j]) {
			// increase matched length and move j ahead
			matched_length++;
			j++;
		} i++; // move i ahead in any case
	}

	// return if matched length is same as length of sub
	return matched_length == n;
}

int main()
{	
	string str = "codingminutes";
	string sub = "cines";

	bool res = is_subseq(str, sub);
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}