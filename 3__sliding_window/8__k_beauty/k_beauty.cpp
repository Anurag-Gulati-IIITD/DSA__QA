/*
PROBLEM STATEMENT:
The k-beauty of an integer num is defined as the number of substrings of num 
when it is read as a string that meet the following conditions:

	- It has a length of k.
	- It is a divisor of num.

Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
*/

#include <bits/stdc++.h>
using namespace std;

int k_beauty(int num, int k)
{
	string s = to_string(num);
    int cnt = 0, i = 0, n = s.length();

    while(i<n-k+1) {
        string sub = s.substr(i, k);
        int div = stoi(sub);
        cout << sub << endl;
        if(div!=0 && num%div==0)
            cnt++;
        i++;
    }
    
    return cnt;
}

int main()
{
	int k = 2, num = 430043;
	cout << k_beauty(num, k) << endl;

	return 0;
}