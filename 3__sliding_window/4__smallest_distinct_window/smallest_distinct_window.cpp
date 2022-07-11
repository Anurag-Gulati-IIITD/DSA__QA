#include <bits/stdc++.h>
using namespace std;

string smallest_distinct(string str)
{
	unordered_map<char, int> fstr, fpat;

	// generating the pattern string
	for(int i=0; i<str.length(); i++)
		fpat[str[i]] = 1;

	// SLIDING WINDOW (EXPANSION + CONTRACTION)
	int cnt = 0;	// counting the number of characters matched
	int st = 0;	// start index
	int min_window_size = INT_MAX;	// minimum window size
	int st_min_size = -1;	// start index of minimum sized window

	for(int i=0; i<str.length(); i++) {

		char ch = str[i];	// i-th character in str
		fstr[ch]++;	// updating the frequency of ch in str

		// if ch is found in the pattern and
		// freq(ch in str) <= freq(ch in pat) 
		if(fpat.find(ch) != fpat.end() && fstr[ch] <= fpat[ch])
			cnt++;	// increase the count of matched characters

		if(cnt == fpat.size()) {	// if the count is equal to pattern size

			// start contracting from the left

			// while str[st] is unwanted, contract from left.
			// unwanted character: 1. either it's not in the pattern
			// 2. or its frequency in current window is more than required
			while(fpat.find(str[st]) == fpat.end() || fstr[str[st]] > fpat[str[st]]) {
				fstr[str[st]]--;	// reduce the frequency from current window
				st++;
			}

			int window_size = i-st+1;	// calculate window size
			if(window_size < min_window_size) {	
				min_window_size = window_size;	// update minimum window size
				st_min_size = st;	// update starting index of minimum size window
			}

		}
	}

	if(st_min_size == -1)	// if no such substring found
		return "No such substring found";

	return str.substr(st_min_size, min_window_size);

}

int main()
{
	string str = "aaaaa";
	cout << smallest_distinct(str) << endl;

	return 0;
}