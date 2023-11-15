#include<bits/stdc++.h>

using namespace std;


int main(void){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	hash<string> hstr;

	string s = "aabbaabb";

	vector<long long> hash(s.size(), 0);
	string str;
	for(int i=0; i<s.size(); i++){
		str.push_back(str[i]);
		hash[i] = hstr(str);
	}

	for(auto &it:hash)
		cout<<it<<" ";
	
	cout<<endl;

	cout<<(hstr("aaa"))<<endl;

	cout<<(649440278-hstr(""))<<endl;

	cout<<(3133554351-649440278)<<endl;

	
	return 0;
}