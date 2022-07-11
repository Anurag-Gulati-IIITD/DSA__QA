#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// string tokenizer function returning 
// the token at key-1
string tokenize(string str, int key)
{
	stringstream ss(str);

	vector<string> tokens;
	string token;

	while(getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	return tokens[key-1];
}

vector<string> key_sort(vector<string> v, int key, bool rev, string comp_type)
{
	// vector of pairs
	// each pair would contain {token at key-1 of i-th string, i-th string}
	vector<pair<string, string>> vec;
	// make the vector by tokenizing strings
	for(int i=0; i<v.size(); i++) {
		vec.push_back(make_pair(v[i], tokenize(v[i], key)));
	}

	// if sorting order is lexicographic
	if(comp_type == "lex") {
		sort(vec.begin(), vec.end(), [](pair<string, string> a, pair<string, string> b) {
			// direct string comparison
			return a.second < b.second;
		});
	} else {	// if numeric
		sort(vec.begin(), vec.end(), [](pair<string, string> a, pair<string, string> b) {
			// converted integer comparisons
			return stoi(a.second) < stoi(b.second);
		});
	}
	
	// if order is to be reversed, then reverse the vector
	if(rev)
		reverse(vec.begin(), vec.end());
	
	// make the final result vector
	vector<string> res;
	for(int i=0; i<vec.size(); i++)
		res.push_back(vec[i].first);

	// return result
	return res;
}

int main()
{
	vector<string> v = {"82 12", "92 022", "77 13"};
	auto vec = key_sort(v, 2, false, "lex");

	for(auto svec : vec) {
		cout << svec << '\n';
	} 

	return 0;
}