#include <bits/stdc++.h>
using namespace std;

void subseq(string s, string out, vector<string> &vec)
{
	// base case
	if(s.size() == 0) {
		vec.push_back(out);
		return;
	}

	// either we include the current character
	subseq(s.substr(1), out+s[0], vec);
	// or we exclude the current character
	subseq(s.substr(1), out, vec);
}

vector<string> sort_subseq(string str)
{
	vector<string> vec;	// result vector
	subseq(str, "", vec);	// get subsequences

	// sorting
	sort(vec.begin(), vec.end(), [](string a, string b) {
		if(a.size() == b.size())	// if the lengths are same
			return a < b;	// lexicographic comparison
		return a.size() < b.size();	// else size-wise comparison
	});

	return vec;
}

int main()
{
	string s = "abcd";
	auto vec = sort_subseq(s);

	for(auto str : vec)
		cout << str << ", ";

	return 0;
}