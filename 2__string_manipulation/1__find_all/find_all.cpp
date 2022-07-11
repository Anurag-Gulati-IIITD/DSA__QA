#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> find_all(string str, string sub)
{
	vector<int> res;
	int idx = str.find(sub);

	while(idx != -1) {
		res.push_back(idx);
		idx = str.find(sub, idx+1);
	}

	return res;
}

int main()
{
	string str = "Hey! STL class contains string. STL stands for Standard Template Library.";
	string sub = "STL";

	auto res = find_all(str, sub);
	for(int idx : res)
		cout << idx << " ";
	cout << endl;

	return 0;
}