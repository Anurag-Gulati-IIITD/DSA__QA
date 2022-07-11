#include <bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    
    string copy = sentence; 
    
    copy[0] = toupper(sentence[0]);
    for(int i=1; sentence[i]!='\0'; i++) {
        if(sentence[i-1]==' ') copy[i] = toupper(sentence[i]);
        else copy[i] = tolower(sentence[i]);
    }

    return copy;
}

int main()
{
	const string str = "This is SO MUCH FUN!";
	cout << normalize(str) << endl;

	return 0;
}