#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

	bool cycle_bfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0);
		queue<pair<int, int>> q;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				q.push({i, -1});
				vis[i]=1;
				while(!q.empty()){
					auto val=q.front();
					q.pop();
					for(auto it:adj[val.first]){
						if(!vis[it]){
							vis[it]=1;
							q.push({it, val.first});
						}
						else if(vis[it] and it!=val.second)
							return true;
					}
				}
			}
		}
		return false;
	}
	
	vector<int> shortest_distance_unit_weight(int src, int n, vector<vector<int>> &adj){
		vector<int> dist(n+1, 1e8);
		queue<int> q;
		dist[src]=0;
		q.push(src);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto it:adj[node]){
				if(dist[node]+1<dist[it]){
					dist[it] = 1+dist[node];
					q.push(it);
				}
			}
		}
		return dist;
	}
	
	bool isBipartite(int n, vector<vector<int>> &adj){
		vector<int> color(n+1, -1);
		for(int i=1; i<=n; i++){
			if(color[i]==-1){
				queue<int> q;
				q.push(i);
				color[i] = 0;
				while(!q.empty()){
					int val = q.front();
					q.pop();
					bool prev = color[val];
					for(auto it:adj[val]){
						if(color[it]==color[val])
							return false;
						else if(color[it]==-1){
							color[it] = !prev;
							q.push(it);
						}
					}
				}
			}
		}
		return true;
	}

	bool cycle_check_dfs(int i, int prev, vector<int> &vis, vector<vector<int>> &adj){
		vis[i]=1;
		for(auto it:adj[i]){
			if(!vis[it])
				return cycle_check_dfs(it, i, vis, adj);
			else if(vis[it] and it!=prev)
				return true;
		}
		return false;
	}
	
	bool cycle_dfs_recur(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0);
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				if(cycle_check_dfs(i, -1, vis, adj))	return true;
			}
		}
		return false;
	}
	
	vector<int> bfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0), res;
		queue<int> q;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					int val=q.front();
					q.pop();
					res.push_back(val);
					for(auto it:adj[val]){
						if(!vis[it]){
							vis[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return res;
	}
	
	void helper(int i, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans){
			vis[i]=1;
			ans.push_back(i);
			for(int it:adj[i]){
				if(!vis[it])
					helper(it, vis, adj, ans);
			}
			return;
	}
	
	vector<int> recur_dfs(int n, vector<vector<int>> &adj){
		
		vector<int> vis(n+1, 0), ans;
		for(int i=1; i<=n; i++){
			if(!vis[i])
				helper(i, vis, adj, ans);
		}
		return ans;
	}
	
	vector<int> iter_dfs(int n, vector<vector<int>> &adj){
		vector<int> vis(n+1, 0), res;
		stack<int> q;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
				while(!q.empty()){
					int val=q.top();
					q.pop();
					res.push_back(val);
					for(auto it:adj[val]){
						if(!vis[it]){
							vis[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return res;
	}

	int main(){
		int n=9;
		vector<vector<int>> adj(n+1);
		adj[0] = {1, 2};
		adj[1] = {0, 2};
		adj[2] = {0, 1,3,4};
		adj[3] = {2, 7};
		adj[4] = {2, 5};
		adj[5] = {4, 6, 9};
		adj[6] = {5, 8};
		adj[7] = {3, 9};
		adj[8] = {6, 9};
		adj[9] = {5, 7, 8};
		vector<int> b = bfs(n, adj), d=shortest_distance_unit_weight(1, n, adj);
		for(auto it:d)
			cout<<it<<" ";
		cout<<endl;
		getch();
		return 0;
	}