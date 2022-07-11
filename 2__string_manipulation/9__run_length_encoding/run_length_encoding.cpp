#include <bits/stdc++.h>
using namespace std;

string run_length_encoding(string str)
{
	string res = "";
	int cur_count = 1;

	for(int i=1; i<str.size(); i++) {
		while(i<str.size() && str[i] == str[i-1]) {
			cur_count++;
			i++;
		}
		res += str[i-1] + to_string(cur_count);
		cur_count = 1;
	}

	if(res.size() >= str.size())
		res = str;

	return res;
}

int main()
{	
	string s = "abc";
	cout << run_length_encoding(s) << endl;

	return 0;
}