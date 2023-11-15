#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
  int t;
  cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    cout<<"1";
    int i=a%2, j =b%2;
    int ans = i+j;
    a = a-i+1;
    b = b-j+1;
  	int m = max(a/2, b/2);
  	ans += m-1;
  	ans += a/m;
  	ans += b/m;
  	cout<<ans<<endl;  
  }
  return 0;
}