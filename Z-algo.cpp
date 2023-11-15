#include<bits/stdc++.h>

using namespace std;

vector<int> zFunction(string &s){
	vector<int> z(s.size(), 0);
	int l=0, r=0;
	for(int i=1; i<s.size(); i++){
		if(i<=r)
			z[i] = min(r-i+1, z[i-l]);
		while(z[i]<s.size() and s[0+z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r){
			l = i;
			r = i+z[i]-1;
		}
	}

	return z;
}


int main(void){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	string s = "abaabac";
	auto z = zFunction(s);

	for(auto &it:z)
		cout<<it<<" ";

	return 0;
}