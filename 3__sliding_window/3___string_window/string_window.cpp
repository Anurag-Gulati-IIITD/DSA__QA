#include <bits/stdc++.h>
using namespace std;

string string_window(string s, string p)
{
	// using arrays as hash-maps

	// lookup table for pattern p
	int FP[256] = {0};
	// lookup table for string s
	int FS[256] = {0};

	for(int i=0; i<p.length(); i++)
		FP[p[i]]++;

	// SLIDING WINDOW
	int cnt = 0;
	int st = 0;	// for contraction
	int min_window_size = INT_MAX;
	int start_idx = -1; // start index for resultant string

	for(int i=0; i<s.length(); i++) {
		// expand the window by including current character
		char ch = s[i];
		FS[ch]++;

		// count how many characters have been matched 
		// till now (between string and pattern)
		if(FP[ch] != 0 && FS[ch] <= FP[ch]) {
			cnt++;
		}

		// if all characters of the pattern have been found in 
		// the current window, then we can start contracting
		if(cnt == p.length()) {
			// start contracting from the left to remove
			// unwanted characters from the window.
			// unwanted char: 
			// 1. either it is not present in pattern
			// 2. or its frequency is higher than required
			while(FP[s[st]] == 0 || FS[s[st]] > FP[s[st]]) {
				FS[s[st]]--;
				st++;
			}

			// note the window size
			int window_size = i - st + 1;
			if(window_size < min_window_size) {
				min_window_size = window_size;
				start_idx = st;	// set start index
			}
		}

	}

	if(start_idx == -1)
		return "No window size";


	return s.substr(start_idx, min_window_size);
}

int main()
{
	string s = "QQQW";
	string p = "QQ";

	cout << string_window(s, p) << endl;

	return 0;
}