#include<bits/stdc++.h>
using namespace std;

// Brute force: O(NK) time
// One optimzation is using deque: O(N) time & O(K) space
vector<int> max_in_window(vector<int> arr,int k){

    vector<int> res;
    
    for(int i=0; i<arr.size()-k+1; i++) {
        int cur_max = INT_MIN;
        for(int j=i; j<i+k; j++) {
            cur_max = max(cur_max, arr[j]);
        }
        res.push_back(cur_max);
    }
    
    return res;
    
}

int main()
{
    int k = 3;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 1};

    auto res = max_in_window(arr, k);
    for(int ele : res)
        cout << ele << " ";
    cout << endl;

    return 0;
}