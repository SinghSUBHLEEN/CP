#include<bits/stdc++.h>

using namespace std;

int upper_bound(vector<vector<int>> &arr, int target){
    int l = 0, r = arr.size();
    while (l<r) {
        int mid = l+(r-l)/2;
        if(arr[mid][0]<=target)
            l = mid + 1;
        else
            r = mid;
    }
    if(l<arr.size() and arr[l][0]<=target)	l++;
    return l;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<vector<int>> arr;
	return 0;
}