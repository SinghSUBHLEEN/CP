#include<bits/stdc++.h>

using namespace std;

int lower_bound(int i, int j, int x, vector<int> &arr){
    int low = i;
    int high = j-1;
    while (low < high) {
        int mid = low + (high - low)/2;
        if (x <= arr[mid]) high = mid;
        else low = mid + 1;
    }

    if(low < j-i && arr[low] < x) {
       low++;
    }

    return low;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	vector<int> v = {0,2,6,7,8,9,32};
	cout<<lower_bound(0, v.size(), 40, v);
	return 0;
}
