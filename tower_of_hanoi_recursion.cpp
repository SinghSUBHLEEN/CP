#include<bits/stdc++.h>

using namespace std;

	void hanoi(int n, int  from, int to, int via){
		if(n==0)
			return;
		
		hanoi(n-1, from, via, to);
		cout<<n<<"("<<from<<"->"<<to<<")"<<endl;
		hanoi(n-1, via, to, from);
		return;
	}
	
	
	int main(){
		int n;
		cout<<"\n Enter the number of disks: ";
		cin>>n;
		hanoi(n, 10, 11, 12);
		return 0;
	}