#include<bits/stdc++.h>

using namespace std;

vector<int> LSP_array(string &s){
	vector<int> lsp(s.size(), 0);
	int len = 0;
	for(int i=1; i<s.size(); ){
		if(s[i]==s[len])
			lsp[i++] = ++len;
		else{
			if(len>0)
				len = lsp[len-1];
			else i++;
		}
	}
	return lsp;
}


int main(void){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	string s = "abaabac";
	auto lsp = LSP_array(s);

	for(auto &it:lsp)
		cout<<it<<" ";

	return 0;
}