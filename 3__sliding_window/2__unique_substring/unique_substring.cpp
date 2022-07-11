#include <bits/stdc++.h>
using namespace std;

string unique_substring(string str)
{
	string ustr = "";

	int i=0, j=0, n=str.size();
	int cur_len=0, max_len=INT_MIN;

	// pair that contains the final range indices
	pair<int, int> idx;

	while(j<n) {	// while we are in the array
		unordered_map<char, int> m;	// map to keep track
		// while the current character is not repeated
		while(j<n && m.find(str[j]) == m.end()) {
			m[str[j]] = j;	// store its index in the map
			j++;	// keep moving
		}
		// when we are out of this loop, it means that
		// we have seen repitition of characters in the substring
		// or the string index j went out of bounds
		cur_len = j - i;	// length of non-repeating substring
		if(cur_len > max_len) {	// if current length is the maximum until now
			max_len = cur_len;	// update max_len
			idx = make_pair(i, j-1);	// set (i, j-1) as the new index range
		}
		// set i to the index next to the last 
		// occurrence of the repeated character
		i = m[str[j]]+1;	
		// update the index of the repeated character in the map
		m[str[j]] = j;
	}

	// extract the substring in the final indices
	for(int k=idx.first; k<=idx.second; k++)
		ustr += str[k];

	return ustr;
}

int main()
{
	string str = "aaaabbb";
	cout << unique_substring(str) << '\n';

	return 0;
}