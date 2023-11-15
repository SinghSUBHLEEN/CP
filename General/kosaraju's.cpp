#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod (int)1e9+7

using namespace std;
using namespace __gnu_pbds;

void getTopo(int i, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ans){
	vis[i] = 1;
	for(auto &it:adj[i]){
		if(!vis[it])
			getTopo(it, vis, adj, ans);
	}

	ans.pb(i);
	return ;
}


int main(void){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	vector<vector<int>> adj = {{1},{2, 3},{3},{0}};
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{2,3},{3,0}};
	int n = 4, e = 5;
	vector<bool> vis(n, 0);
	vector<int> topo;
	for(int i=0; i<n; i++){
		if(!vis[i])
			getTopo(i, vis, adj, topo);
	}

	vector<vector<int>> rev(n);
	for(int i=0; i<edges.size(); i++)
		rev[edges[i][1]].push_back(edges[i][0]);

	

	return 0;
}