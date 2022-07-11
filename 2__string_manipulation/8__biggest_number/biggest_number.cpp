#include <bits/stdc++.h>
using namespace std;

string biggest_number(vector<string> vec)
{
	sort(vec.begin(), vec.end(), [](string a, string b) {
		// check which is greater after concatenation
		// a+b or b+a
		return a+b > b+a;
	});

	string res = "";
	for(string str : vec)
		res += str;

	return res;
}

int main()
{
	vector<string> vec = {"10", "11", "20", "30", "3"};
	cout << biggest_number(vec) <<endl;

	return 0;
}