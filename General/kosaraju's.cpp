#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod (int)1e9+7

using namespace std;

void topo(int i, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ans){
    vis[i] = 1;
    for(auto &it:adj[i]){
        if(!vis[it])
            topo(it, vis, adj, ans);
    }
    ans.push_back(i);
    return ;
}

void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ans){
    vis[i] = 1;
    ans.push_back(i);
    for(auto &it:adj[i]){
        if(!vis[it])
            dfs(it, vis, adj, ans);
    }
    return ;
}

vector<vector<int>> getStronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<vector<int>> adj(n), rev(n), ans;
    for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        rev[it[1]].push_back(it[0]);
    }

    vector<int> t;
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]) 
            topo(i, vis, adj, t);
    }
    vis = vector<bool>(n, false);
    vector<int> d;
    for(int i=n-1; i>=0; i--){
        if(!vis[t[i]]){
            d = {};
            dfs(t[i], vis, rev, d);
            ans.push_back(d);
        }
    }
    return ans;
}


int main(void){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> adj = {{1},{2, 3},{3},{0}};
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{2,3},{3,0},{2,4},{4,5},{5,6},{6,4}};
	int n = 7;
	auto ans = getStronglyConnectedComponents(n, edges);
	cout<<ans.size()<<endl;
	for(auto &it:ans){
		for(auto &ele:it)
			cout<<ele<<" ";
		cout<<endl;
	}

	return 0;
}