#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> pair_sum(vector<int> &arr, int target)
{
    unordered_set<int> set; // set to keep track of pairs

    int n = arr.size(); // size of input array
    // traverse through the array
    for(int i=0; i<n; i++) {
        // if target - arr[i] found in set,
        // then make a pair of the two and return
        if(set.find(target-arr[i]) != set.end())
            return make_pair(arr[i], target-arr[i]);
        else
            set.insert(arr[i]); // insert the element in set
    }

    return make_pair(INT_MIN, INT_MIN); // return result
}

int main()
{
    vector<int> arr = {-1, 5, 2, 0, 8, 10, 4, -3, -1, 0, 3};
    int target = 7;

    auto p = pair_sum(arr, target);
    
    cout << p.first << " " << p.second << '\n';
    cout << endl;   

    return 0;
}