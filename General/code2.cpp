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
	for(int i=1; i<=n; i++){
		int c;
		cin>>c;
		if(i>c)
			arr.push_back({c, i});
	}
	sort(begin(arr), end(arr));
	int ans = 0;
	for(int i=0; i<arr.size(); i++){
		int ind = upper_bound(arr, arr[i][1]);
		if(ind==-1) continue;
		ans += arr.size()-ind;
	}
	cout<<ans<<endl;
	return 0;
}