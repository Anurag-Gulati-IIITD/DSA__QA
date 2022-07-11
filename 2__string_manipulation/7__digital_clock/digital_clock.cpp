#include <bits/stdc++.h>
using namespace std;

string digital_clock(int minutes)
{
	string res;

	int hrs = minutes/60;
	int min = minutes%60;
	string min_str = min<10?"0"+to_string(min):to_string(min);
	res = to_string(hrs) + ":" + min_str;

	return res;
}

int main()
{
	int minutes = 1180;
	cout << digital_clock(minutes) << endl;

	return 0;
}