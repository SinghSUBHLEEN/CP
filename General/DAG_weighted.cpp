#include<bits/stdc++.h>

using namespace std;

	vector<int> dijkstra_s_algo_shortest_parth_undir_weighted(int src, int n, vector<vector<pair<int, int>>> &adj){
		vector<int> dist(n, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, src});
		dist[src]=0;
		while(!pq.empty()){
			auto val = pq.top();
			pq.pop();
			for(auto it:adj[val.second]){
				if(dist[val.second]+it.second < dist[it.first]){
					dist[it.first] =  dist[val.second]+it.second;
					pq.push({dist[it.first], it.first});
				}
			}
		}
		return dist;
	}

	void topo_dfs(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &ans){
		vis[node] = 1;
		for(auto it:adj[node]){
			if(!vis[it.second])
				topo_dfs(it.second, vis, adj, ans);
		}
		ans.push(node);
		return;
	}
	
	stack<int> get_topo(int n, vector<vector<pair<int, int>>> &adj){
		vector<int> vis(n+1, 0);
		stack<int> ans;
		for(int i=0; i<=n; i++){
			if(!vis[i])
				topo_dfs(i, vis, adj, ans);
		}
		return ans;
	}
	
	vector<int> get_shortest_path_DAG_weighted(int src, int n, vector<vector<pair<int, int>>> &adj){
		stack<int> st = get_topo(n, adj);
		vector<int> ans(n, INT_MAX);
		ans[src]=0;
		while(!st.empty()){
			int node = st.top();
			st.pop();
			for(auto it:adj[node])
				ans[it.second] = min(ans[node]+it.first, ans[it.second]);
		}
		return ans;
	}

	int main(){
		#ifndef ONLINE_JUDGE
			freopen("intput.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		#endif
		int n=7;
		vector<vector<pair<int, int>>> adj(n);
		adj[0] = {{1,2}, {2,6}};
		adj[1] = {{0,2}, {3,5}};
		adj[2] = {{0,6}, {3,8}};
		adj[3] = {{1,5}, {2,8}};
		adj[4] = {{3,10}, {5,6}, {6,2}};
		adj[5] = {{3,15}, {4,6}, {6,6}};
		adj[6] = {{4,2}, {5,6}};
		vector<int> ans = dijkstra_s_algo_shortest_parth_undir_weighted(0, n, adj);
		for(auto it:ans)
			cout<<it<<' ';
		cout<<endl;
		return 0;
	}