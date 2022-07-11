#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str = "This is a sunny day";

	// create a string stream object
	stringstream ss(str);

	// vector of tokens
	vector<string> tokens;

	string token;
	// while ss gets a token
	while(getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	// print tokens
	for(auto tok : tokens)
		cout << tok << '\n';
	cout << endl;

	return 0;
}