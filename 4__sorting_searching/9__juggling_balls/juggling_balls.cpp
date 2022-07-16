#include <bits/stdc++.h>
using namespace std;

vector<int> sort_balls(vector<int> balls)
{
	int n=balls.size();
	int lo=0, mid=0, hi=n-1;

	while(mid<=hi) {	// while the array isn't sorted
		if(balls[mid] == 0)	// if the element is 0
			swap(balls[lo++], balls[mid++]);	// swap it with lo and move both lo and mid
		else if(balls[mid] == 1)	// if the element is 1
			mid++;	// just move on
		else	// if the element is 2
			swap(balls[mid], balls[hi--]);	// swap with hi and don't move mid
	}

	return balls;
}

int main()
{
	vector<int> balls = {0,0,0,0,1,2,2,1,1,1,1,1,2,1};
	auto res = sort_balls(balls);

	for(auto ele : res)
		cout << ele << " ";
	cout << endl;

	return 0;
}