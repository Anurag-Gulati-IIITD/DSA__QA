#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void space_20(char *str)
{
	// counting the number of spaces
	int spaces = 0;
	for(int i=0; i<strlen(str); i++)
		if(str[i] == ' ')
			spaces++;

	// finding the index for null character
	// in the new string
	int idx = strlen(str) + 2*spaces;
	str[idx] = '\0';
	// traversal
	for(int i=strlen(str)-1; i>=0; i--) {
		// if space encountered, replace with %20
		if(str[i] == ' ') { 
			str[idx-1] = '0';
			str[idx-2] = '2';
			str[idx-3] = '%';
			idx -= 3;
		} else {	// else just copy and move on
			str[idx-1] = str[i];
			idx--;
		}
	}	
}

int main()
{
	char str[1000];
	cin.getline(str, 100);
	space_20(str);
	cout << str << endl;

	return 0;
}